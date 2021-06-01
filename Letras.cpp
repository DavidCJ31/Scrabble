#include "Letras.h"
void _Letras::CrearCopia() {
	lee.open("Letras.dat", ios::in | ios::binary);
	int i = 0;
	lee >> letra;
	while (!lee.eof()) {
		lee >> valor;
		Letra[i] = letra;
		CopiaLetras[i] = letra;
		Valores[i] = valor;
		CopiaValores[i] = valor;
		lee >> letra;
		i++;
	}
	lee.close();
	cout << "\nMuestra las letras en el vector" << endl;
	for (int i = 0; i < 99; i++) {
		cout << "[" << Letra[i] << "]";
	}
	cout << "\nMuestra los valores en el vector" << endl;
	for (int i = 0; i < 99; i++) {
		cout << "[" << Valores[i] << "]";
	}
}

bool _Letras::repetida(int ficha) {
	for (int i = 0; i<7; i++) {
		if (numeros[i] == ficha) {
			return true;
		}
	}
	return false;
}
void _Letras::EliminaLetra(string &L) {
	bool repetido = false;
	for (int i = 0; i<cantidad; i++) {
		if (repetido != true) {
			if (L == Letra[i]) {
				for (int j = i; j<cantidad; j++) {
					 Letra[j] = Letra[j + 1];
					Valores[j] = Valores[j + 1];
				}
				repetido = true;
			}
		}
	}
	cantidad--;
}
void _Letras::RepartirPrimeraVez() //Reparte las fichas del jugador
{
	srand(time(NULL));
	string L;
	int cont = 0;
	if (cantidad == 0) {
		cout << "La cadena ya esta vacia" << endl;
		exit(1);
	}
	do {
		ficha = rand() % cant;
		if (repetida(ficha) != true) {
			numeros[cont] = ficha;
			cont++;
			cant--;
		}
	} while (cont<7);
	for (int i = 0; i<7; i++) {
		L = Letra[numeros[i]];
		EliminaLetra(L);
		Fichas[i] = L;
	}
	cout << "\n\nCadena" << endl;
	for (int i = 0; i<cantidad; i++) {
		cout << "[" << Letra[i] << "]";
	}
	cout << "\n\nFichas del jugador" << endl;
	for (int i = 0; i<7; i++) {
		cout << "[" << Fichas[i] << "]";
	}
}
void _Letras::RellenarFichas() {
	int ficha;
	for (int i = 0; i < 7; i++) {
		if (Fichas[i] == " ") {
			if (cantidad == 0) {
				cout << "La cadena ya esta vacia" << endl;
				exit(1);
			}
			else {
				ficha = rand() % cant;
				Fichas[i] = Letra[ficha];
				EliminaLetra(Fichas[i]);
				cant--;
			}
		}
	}
}
void _Letras::DevolverFichas() {
	int CONTA = 0;
	for (int i = 0; i < 7; i++) {
		if (Fichas[i] == " ") {
			Fichas[i] = CopiaPalabra[CONTA];
			CONTA++;
		}
	}
	I = 0;
}
void _Letras::Mostrar() {
	int contadorMuestra = 1;
	cout << "\n\nCadena" << endl;
	for (int j = 0; j < cantidad; j++) {
		if (Letra[j] == Letra[j + 1]) {
			contadorMuestra++;
		}
		else {
			cout << "Letra: " << Letra[j] << " ->";
			cout << "Cantidad: " << contadorMuestra << " ->";
			cout << "Valor: " << Valores[j] << endl;
			contadorMuestra = 1;
		}
	}
	cout << "\nCantidad de letras: " << cantidad << endl;
	for (int i = 0; i<7; i++) {
		cout << "[" << Fichas[i] << "]";
	}
}

void _Letras::Verificar() {
	LlenaCopia();
	if (PonerPrimeraVez == 0) {
		if (Tablero[7][7] != "**") {
			if ((Existe(Palabra) == true || Existe(Palabra1) == true) || (Existe(Palabra) == true && Existe(Palabra1) == true)) {
				cout << "\nFELICIDADES ESTA EN EL DICCIONARIO\n";
				RellenarFichas();
				if (Existe(Palabra) == true) {
					total += puntos;
				}
				if (Existe(Palabra1) == true) {
					total+= puntos1;
				}
				Palabra = "";
				Palabra1 = "";
				for (int i = 0; i < letra_; i++) {
					PosI[i] = 0;
					PosJ[i] = 0;
					auxPalabra[i] = "";
					CopiaPalabra[i] = "";
				}
				I = 0;
				IJ = 0;
				puntos = 0;
				puntos1 = 0;
				PonerPrimeraVez++;
			}
		}
		else {
			cout << "\nTIENES QUE TOCAR EL CENTRO ->(**) CON ALGUNA LETRA\n";
			DevolverFichas();
			for (int i = 0; i < letra_; i++) {
				Tablero[PosI[i]][PosJ[i]] = auxPalabra[i];
				CopiaPalabra[i] = "";
			}
			Palabra = "";
			Palabra1 = "";
			I = 0;
			IJ = 0;
			puntos = 0;
			puntos1 = 0;
		}

	}
	else {
		if ((Existe(Palabra) == true || Existe(Palabra1) == true) || (Existe(Palabra) == true && Existe(Palabra1) == true)) {
			cout << "\nFELICIDADES ESTA EN EL DICCIONARIO\n";
			RellenarFichas();
			if (Existe(Palabra) == true) {
				total += puntos;
			}
			if (Existe(Palabra1) == true) {
				total += puntos1;
			}
			Palabra = "";
			Palabra1 = "";
			for (int i = 0; i < letra_; i++) {
				PosI[i] = 0;
				PosJ[i] = 0;
				auxPalabra[i] = "";
				CopiaPalabra[i] = "";
			}
			I = 0;
			IJ = 0;
			puntos = 0;
			puntos1 = 0;
		}
		else {
			cout << "\nLA PALABRA NO ESTA EN EL DICCIONARIO\n";
			DevolverFichas();
			for (int i = 0; i < letra_; i++) {
				Tablero[PosI[i]][PosJ[i]] = auxPalabra[i];
				CopiaPalabra[i] = "";
			}
			Palabra = "";
			Palabra1 = "";
			I = 0;
			IJ = 0;
			puntos = 0;
			puntos1 = 0;
		}
	}
}

void _Letras::Comodin(string L) {
	string  opc;
	cout << "Digite la letra que quieres" << endl;
	cout << "A|B|C|D|E|F|G|H|I\nJ|L|M|N|O|P|Q|R|S\nT|U|V|Y|X|Z|LL|RR|CH";
	cout << "Letra:";
	cin >> opc;
	for (int i = 0; i < 7; i++) {
		if (Fichas[i] == "/") {
			Fichas[i] == opc;
		}
	}
}
void _Letras::CambiarLetras(string &L) {
	bool repetido = false;
	for (int i = 0; i<7; i++) {
		if (repetido != true) {
			if (L == Fichas[i]) {
				int cont = 0;
				int ficha, numero;
				do {
					ficha = rand() % cant;
					if (repetida(ficha) != true && Letra[ficha] != L) {
						numero = ficha;
						cont++;
					}
				} while (cont<1);
				Fichas[i] = Letra[numero];
				Letra[numero] = L;
				repetido = true;
			}
		}
	}
	cout << "\n\nCadena" << endl;
	for (int i = 0; i<cantidad; i++) {
		cout << "[" << Letra[i] << "]";
	}
	cout << "\n\nLetras restantes: " << cantidad << endl;
	cout << "\n\nFichas del jugador" << endl;
	for (int i = 0; i<7; i++) {
		cout << "[" << Fichas[i] << "]";
	}
}
bool _Letras::InsertaPrimeraVez(int f, int c) {
	if (f == 7 || c == 7) {
		return true;
	}
	return false;
}
bool _Letras::Inserta(int f, int c)
{
	if (valida(f, c) == true) {
		return true;
	}
	return false;
}
bool _Letras::valida(int f, int c)
{
	if (Tablero[f][c] == "A" || Tablero[f][c] == "B" || Tablero[f][c] == "C" || Tablero[f][c] == "D" || Tablero[f][c] == "E" || Tablero[f][c] == "F" || Tablero[f][c] == "G" || Tablero[f][c] == "H" || Tablero[f][c] == "I" || Tablero[f][c] == "J" || Tablero[f][c] == "L" || Tablero[f][c] == "M" || Tablero[f][c] == "N" || Tablero[f][c] == "O" || Tablero[f][c] == "P" || Tablero[f][c] == "Q" || Tablero[f][c] == "R" || Tablero[f][c] == "S" || Tablero[f][c] == "T" || Tablero[f][c] == "U" || Tablero[f][c] == "V" || Tablero[f][c] == "X" || Tablero[f][c] == "Z" || Tablero[f][c] == "RR" || Tablero[f][c] == "CH" || Tablero[f][c] == "LL" || Tablero[f][c] == "Y") {
		return false;
	}
	if (Tablero[f][c] == "**") {
		return true;
	}
	if (Tablero[f - 1][c] == "" && Tablero[f + 1][c] == "" && Tablero[f][c - 1] == "" && Tablero[f][c + 1] == "") {
		return false;
	}
	if ((Tablero[f - 1][c] == "A" || Tablero[f - 1][c] == "B" || Tablero[f - 1][c] == "C" || Tablero[f - 1][c] == "D" || Tablero[f - 1][c] == "E" || Tablero[f - 1][c] == "F" || Tablero[f - 1][c] == "G" || Tablero[f - 1][c] == "H" || Tablero[f - 1][c] == "I" || Tablero[f - 1][c] == "J" || Tablero[f - 1][c] == "L" || Tablero[f - 1][c] == "M" || Tablero[f - 1][c] == "N" || Tablero[f - 1][c] == "O" || Tablero[f - 1][c] == "P" || Tablero[f - 1][c] == "Q" || Tablero[f - 1][c] == "R" || Tablero[f - 1][c] == "S" || Tablero[f - 1][c] == "T" || Tablero[f - 1][c] == "U" || Tablero[f - 1][c] == "V" || Tablero[f - 1][c] == "X" || Tablero[f - 1][c] == "Z" || Tablero[f - 1][c] == "RR" || Tablero[f - 1][c] == "CH" || Tablero[f - 1][c] == "LL" || Tablero[f - 1][c] == "Y") ||
		(Tablero[f + 1][c] == "A" || Tablero[f + 1][c] == "B" || Tablero[f + 1][c] == "C" || Tablero[f + 1][c] == "D" || Tablero[f + 1][c] == "E" || Tablero[f + 1][c] == "F" || Tablero[f + 1][c] == "G" || Tablero[f + 1][c] == "H" || Tablero[f + 1][c] == "I" || Tablero[f + 1][c] == "J" || Tablero[f + 1][c] == "L" || Tablero[f + 1][c] == "M" || Tablero[f + 1][c] == "N" || Tablero[f + 1][c] == "O" || Tablero[f + 1][c] == "P" || Tablero[f + 1][c] == "Q" || Tablero[f + 1][c] == "R" || Tablero[f + 1][c] == "S" || Tablero[f + 1][c] == "T" || Tablero[f + 1][c] == "U" || Tablero[f + 1][c] == "V" || Tablero[f + 1][c] == "X" || Tablero[f + 1][c] == "Z" || Tablero[f + 1][c] == "RR" || Tablero[f + 1][c] == "CH" || Tablero[f + 1][c] == "LL" || Tablero[f + 1][c] == "Y") ||
		(Tablero[f][c - 1] == "A" || Tablero[f][c - 1] == "B" || Tablero[f][c - 1] == "C" || Tablero[f][c - 1] == "D" || Tablero[f][c - 1] == "E" || Tablero[f][c - 1] == "F" || Tablero[f][c - 1] == "G" || Tablero[f][c - 1] == "H" || Tablero[f][c - 1] == "I" || Tablero[f][c - 1] == "J" || Tablero[f][c - 1] == "L" || Tablero[f][c - 1] == "M" || Tablero[f][c - 1] == "N" || Tablero[f][c - 1] == "O" || Tablero[f][c - 1] == "P" || Tablero[f][c - 1] == "Q" || Tablero[f][c - 1] == "R" || Tablero[f][c - 1] == "S" || Tablero[f][c - 1] == "T" || Tablero[f][c - 1] == "U" || Tablero[f][c - 1] == "V" || Tablero[f][c - 1] == "X" || Tablero[f][c - 1] == "Z" || Tablero[f][c - 1] == "RR" || Tablero[f][c - 1] == "CH" || Tablero[f][c - 1] == "LL" || Tablero[f][c - 1] == "Y") ||
		(Tablero[f][c + 1] == "A" || Tablero[f][c + 1] == "B" || Tablero[f][c + 1] == "C" || Tablero[f][c + 1] == "D" || Tablero[f][c + 1] == "E" || Tablero[f][c + 1] == "F" || Tablero[f][c + 1] == "G" || Tablero[f][c + 1] == "H" || Tablero[f][c + 1] == "I" || Tablero[f][c + 1] == "J" || Tablero[f][c + 1] == "L" || Tablero[f][c + 1] == "M" || Tablero[f][c + 1] == "N" || Tablero[f][c + 1] == "O" || Tablero[f][c + 1] == "P" || Tablero[f][c + 1] == "Q" || Tablero[f][c + 1] == "R" || Tablero[f][c + 1] == "S" || Tablero[f][c + 1] == "T" || Tablero[f][c + 1] == "U" || Tablero[f][c + 1] == "V" || Tablero[f][c + 1] == "X" || Tablero[f][c + 1] == "Z" || Tablero[f][c + 1] == "RR" || Tablero[f][c + 1] == "CH" || Tablero[f][c + 1] == "LL" || Tablero[f][c + 1] == "Y")) {
		return true;
	}
	if (Tablero[f - 1][c] != "TP" || Tablero[f + 1][c] != "TP" || Tablero[f][c - 1] != "TP" || Tablero[f][c + 1] != "TP" || Tablero[f - 1][c] != "DP" || Tablero[f + 1][c] != "DP" || Tablero[f][c - 1] != "DP" && Tablero[f][c + 1] != "DP" && Tablero[f - 1][c] != "DL" && Tablero[f + 1][c] != "DL" && Tablero[f][c - 1] != "DL" && Tablero[f][c + 1] != "DL" && Tablero[f - 1][c] != "TL" && Tablero[f + 1][c] != "TL" && Tablero[f][c - 1] != "TL" && Tablero[f][c + 1] != "TL") {
		return false;
	}
}
void _Letras::Poner() {
	string L, Aux1, Aux2;
	int f, c;
	int res;
	if (PonerPrimeraVez == 0) {
		do {
			cout << "\nPalabra: " << Palabra << endl;
			cout << "\nFichas del jugador" << endl;
			for (int i = 0; i < 7; i++) {
				cout << "[" << Fichas[i] << "]";
			}
			Mostrar_Tablero();
			cout << "\nDigite la letra que desea poner" << endl;
			cin >> L;
			if (Esta(L) == true) {
				if (L == "/") {
					Comodin(L);
				}
				CopiaPalabra[I] = L;
				cout << "Fila:" << endl;
				cin >> f;
				cout << "Columna:" << endl;
				cin >> c;
				PosI[IJ] = f;
				PosJ[IJ] = c;
				if (InsertaPrimeraVez(f, c) == true) { // VERIFICA QUE PASE POR LA POSISION 7,7
					auxPalabra[IJ] = Tablero[f][c];
					Tablero[f][c] = L;
					Fichas[Pos] = " ";
					cout << "\nInsertada Correctamente\n";

					for (int i = 0; i < cantidad; i++) {       // Palabra
						puntos = 0;
						if (Tablero[f][i] != "TP"&& Tablero[f][i] != "DL" && Tablero[f][i] != "" && Tablero[f][i] != "TL"&& Tablero[f][i] != "DP"&& Tablero[f][i] != "*") {

							if (Tablero[f][c + 1] == "" || Tablero[f][c - 1] == "" || Tablero[f][c + 1] == "*" || Tablero[f][c - 1] == "*" || Tablero[f][c + 1] == "TL" || Tablero[f][c - 1] == "TL" || Tablero[f][c + 1] == "TP" || Tablero[f][c - 1] == "TP" || Tablero[f][c + 1] == "DL" || Tablero[f][c - 1] == "DL" || Tablero[f][c + 1] == "DP" || Tablero[f][c - 1] == "DP") { // Suma las letras horizontal
								Aux1 += Tablero[f][i];
								cout << "Suma:" << Suma << endl;
								int UnaVez1 = 0;
								for (int j = 0; j < 99; j++) {
									if (UnaVez1 == 0) {
										if (Tablero[f][i] == CopiaLetras[j]) {
											Suma += CopiaValores[j];
											UnaVez1++;
										}
									}
								}
							}
						}
					}
					puntos = Suma;
					Suma = 0;
					Palabra = Aux1;
					Aux1 = "";
					for (int i = 0; i < cantidad; i++) {       //Palabra1
						puntos1 = 0;
						if (Tablero[i][c] != "TP"&& Tablero[i][c] != "DL" && Tablero[i][c] != ""&& Tablero[i][c] != "TL"&& Tablero[i][c] != "DP"&& Tablero[i][c] != "*") {
							if (Tablero[f + 1][c] == "" || Tablero[f - 1][c] == "" || Tablero[f + 1][c] == "*" || Tablero[f - 1][c] == "*" || Tablero[f - 1][c] == "TL" || Tablero[f - 1][c] == "TP" || Tablero[f - 1][c] == "DL" || Tablero[f - 1][c] == "DP" || Tablero[f + 1][c] == "TP" || Tablero[f + 1][c] == "TL" || Tablero[f + 1][c] == "DP" || Tablero[f + 1][c] == "DL") { // Suma las letras vertical
								Aux2 += Tablero[i][c];
								cout << "Suma:" << Suma1 << endl;
								int UnaVez2 = 0;
								for (int j = 0; j < 99; j++) {
									if (UnaVez2 == 0) {
										if (Tablero[i][c] == CopiaLetras[j]) {
											Suma1 += CopiaValores[j];
											UnaVez2++;
										}
									}
								}
							}
						}
					}
					puntos1 = Suma1;
					Suma1 = 0;
					Palabra1 = Aux2;
					Aux2 = "";
					Mostrar_Tablero();
					I++;
					IJ++;
				}
				else {
					DevolverFichas();
					Palabra = "";
					cout << "\nNo Insertada\n";
				}
			}
			else {
				cout << "\nNo tienes esa letra" << endl;
			}
			cout << "\nPalabra HORIZONTAL: " << Palabra << endl;
			cout << "Puntos: " << puntos << endl;
			cout << "\nPalabra VERTICAL: " << Palabra1 << endl;
			cout << "Puntos: " << puntos1 << endl;
			cout << "\nPoner otra \n1=Si \n2=No" << endl;
			cin >> res;
		} while (res == 1);
		CONT++;
	}
	else {
		do {
			cout << "\nPalabra: " << Palabra << endl;
			cout << "\nPalabra: " << Palabra1 << endl;
			cout << "\nFichas del jugador" << endl;
			for (int i = 0; i < 7; i++) {
				cout << "[" << Fichas[i] << "]";
			}
			Mostrar_Tablero();
			cout << "\nDigite la letra que desea poner" << endl;
			cin >> L;
			if (Esta(L) == true) {

				CopiaPalabra[I] = L;
				cout << "Fila:" << endl;
				cin >> f;
				cout << "Columna:" << endl;
				cin >> c;
				PosI[IJ] = f;
				PosJ[IJ] = c;
				if (Inserta(f, c) == true) {
					auxPalabra[IJ] = Tablero[f][c];
					Tablero[f][c] = L;
					Fichas[Pos] = " ";
					cout << "\nInsertada Correctamente\n";

					for (int i = 0; i < cantidad; i++) {       // Palabra
						puntos = 0;
						if (Tablero[f][i] != "TP"&& Tablero[f][i] != "DL" && Tablero[f][i] != "" && Tablero[f][i] != "TL"&& Tablero[f][i] != "DP") {

							if (Tablero[f][c + 1] == "" || Tablero[f][c - 1] == "") { // Suma las letras horizontal
								Aux1 += Tablero[f][i];
								cout << "Suma:" << Suma << endl;
								int UnaVez1 = 0;
								for (int j = 0; j < 99; j++) {
									if (UnaVez1 == 0) {
										if (Tablero[f][i] == CopiaLetras[j]) {
											Suma += CopiaValores[j];
											UnaVez1++;
										}
									}
								}
							}
						}
					}
					puntos = Suma;
					Suma = 0;
					Palabra = Aux1;
					Aux1 = "";
					for (int i = 0; i < cantidad; i++) {       //Palabra1
						puntos1 = 0;
						if (Tablero[i][c] != "TP"&& Tablero[i][c] != "DL" && Tablero[i][c] != ""&& Tablero[i][c] != "TL"&& Tablero[i][c] != "DP") {
							if (Tablero[f][c + 1] == "" || Tablero[f][c - 1] == "") { // Suma las letras vertical
								Aux2 += Tablero[i][c];
								cout << "Suma:" << Suma1 << endl;
								int UnaVez2 = 0;
								for (int j = 0; j < 99; j++) {
									if (UnaVez2 == 0) {
										if (Tablero[i][c] == CopiaLetras[j]) {
											Suma1 += CopiaValores[j];
											UnaVez2++;
										}
									}
								}
							}
						}
					}
					puntos1 = Suma1;
					Suma1 = 0;
					Palabra1 = Aux2;
					Aux2 = "";
					Mostrar_Tablero();
					I++;
					IJ++;
				}
				else {
					DevolverFichas();
					Palabra = "";
					cout << "\nNo Insertada\n";
				}
			}
			else {
				cout << "\nNo tienes esa letra" << endl;
			}
			cout << "\nPalabra HORIZONTAL: " << Palabra << endl;
			cout << "Puntos: " << puntos << endl;
			cout << "\nPalabra VERTICAL: " << Palabra1 << endl;
			cout << "Puntos: " << puntos1 << endl;
			cout << "\nPoner otra \n1=Si \n2=No" << endl;
			cin >> res;
		} while (res == 1);
		CONT++;
	}
}
//void _Letras::Leer() {
//	lee.open("Letras.dat", ios::in | ios::binary);
//	lee >> letra;
//	while (!lee.eof()) {
//		lee >> valor;
//		cout << letra << " " << valor;
//		cout << endl << endl;
//		lee >> letra;
//	}
//	lee.close();
//}
bool _Letras::Esta(string &L) {
	Pos = 0;
	bool Si = false;
	for (int i = 0; i<7; i++) {
		if (Si != true) {
			if (L == Fichas[i]) {
				Palabra = L;
				return true;
			}
		}
		Pos++;
	}
	return false;
}
void _Letras::Menu() {

	int opc;
	int cont = 0;
	string L;
	int Si = 2;
	CrearCopia();
	do
	{
		if (cont == 0) {
			LlenaTablero();
			RepartirPrimeraVez();
			cont++;
		}
		cout << endl << endl;
		system("pause");
		system("cls");
		//cout << "\nPuntos del Jugador: " << totalPuntos << endl;
		cout << "[1] Insertar: \n[2] Verificar: \n [3] Cambiar: "; cin >> opc;
		switch (opc)
		{
		case 1:Poner();
			break;
		case 2:Verificar();
			break;
		case 3:Cambiar();
			break;
		}
		
	} while (opc == 1 || opc == 2);
}

void _Letras::Cambiar() {
	bool cambio = 1;
	do {
		string L;
		cout << "Fichas Jugador" << endl;
		for (int i = 0; i < 7; i++) {
			cout << "[" << Fichas[i] << "]";
		}
		cout << "\n\nLetras restantes: " << cantidad << endl;
		cout << "\nLetra a cambiar: "; cin >> L;
		CambiarLetras(L);
		cout << "\nCambiar otra \n[1]  Si \n [0] No: "; cin >> cambio;
	} while (cambio == 1);
}