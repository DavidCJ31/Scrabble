#include "Scrabble.h"

Scrabble::Scrabble() {
	letra = " ";
	cantidad_letras = 100;
	bandera = false;
}

Scrabble::~Scrabble() {}

string Scrabble::instrucciones() {
	stringstream p;
	//MODIFICAR
		/*El juego consiste en formar palabras de dos o más letras, y colocarlas en el tablero,
		horizontal o verticalmente, de manera que puedan ser leídas de izquierda a derecha o
		de arriba hacia abajo.
		Después de la jugada inicial(art. 6), cada palabra(art. 9) debe ligarse con alguna de
		las incorporadas.*/
		/*El turno de salida será definido por sorteo. A esos efectos, cada jugador sacará una
		ficha de la bolsa. El que saque la ficha más cercana a la A comenzará. El comodín
		gana a todas. En caso de empate sacarán otra ficha hasta desempatar.
		Los jugadores podrán verificar que todas las letras sacadas para el sorteo se
		reintrodujeron en la bolsa antes de iniciar la partida.*/
		/*Las palabras pueden formarse de las siguientes maneras:
		9.1 Añadiendo una o más fichas a una palabra que esté colocada sobre el tablero.
		9.2 Colocando una palabra que se cruce con otra en el tablero. La nueva palabra debe
		utilizar una de las letras de la palabra que ya se encuentra en el tablero.
		9.3 Colocando una palabra completa paralelamente a otra que ya se encuentra en el
		tablero, de modo que las fichas contiguas también forman palabras completas. */
		/*El valor de cada letra está indicado con una cifra en la parte inferior de la ficha. La
		puntuación total obtenida en cada turno se calcula sumando el valor de las letras
		utilizadas en las palabras que se hayan formado en ese turno, más los puntos
		obtenidos por haber colocado una o más fichas en casillas con premio. */
		/*Al colocar una ficha en una casilla azul celeste (doble tanto de letra), se duplica el
		valor de dicha letra; y al colocarla en una casilla azul marino (triple tanto de letra), se
		triplica su valor. */
	//Explicar la matriz, las letras, los puntos, los premios, opciones para cada jugador.
	return p.str();
}


void Scrabble::menu() {
	/**/
	int opcion = 0;
	cout << endl;
	cout << "BIENVENIDOS A SCRABBLE" << endl;
	cout << "[1] Como jugar" << endl;
	cout << "[2] Cantidad de jugadores" << endl;
	cout << "Digite la opcion que desea: "; cin >> opcion;
	switch (opcion){
		case 1:  instrucciones();
			break;
		case 2: _cantidadJugadores();
			break;
		default: cout << "Opcion no disponible" << endl;
			break;
	}
}
int Scrabble::_cantidadJugadores() {
	char opcion;
	cout << endl;
	cout << "[A] CANTIDAD DE JUGADORES = 2" << endl;
	cout << "[B] CANTIDAD DE JUGADORES = 3" << endl;
	cout << "[C] CANTIDAD DE JUGADORES = 4" << endl;
	cout << "Digite la opcion que desea: "; cin >> opcion;
	cout << endl;
	//strupr(opcion);
	switch (opcion) {
	case 'A': {
		return cantidadJugadores = 2;
		cout << "CANTIDAD DE JUGADORES = 2" << endl;
		break;
	}
	case 'B': {
		return cantidadJugadores = 3;
		cout << "CANTIDAD DE JUGADORES = 3" << endl;
		break;
	}
	case 'C': {
		return cantidadJugadores = 4;
		cout << "CANTIDAD DE JUGADORES = 4" << endl;
		break;
	}
	default: cout << "Opcion no disponible" << endl;
		break;
	}
}

void Scrabble::inicializaJugadores() {
	jugador1 = new Jugador;
	jugador2 = new Jugador;
	jugador3 = new Jugador;
	jugador4 = new Jugador;
	jugador1->setTurno(true);
	jugador2->setTurno(false);
	jugador3->setTurno(false);
	jugador4->setTurno(false);
}

bool Scrabble::winner() {
	return false;
}

void Scrabble::Jugar()  
{
	menu();
	LlenaTablero();
	Mostrar_Tablero();
	inicializaJugadores();
	system("pause");
	system("cls");
	
	while (!winner()) {

		if (cantidadJugadores == 2) {
			if (bandera != true) {
				jugador1->RellenarFichas();
				jugador2->RellenarFichas();
				bandera = true;
			}
			if (jugador1->getTurno() == true && jugador2->getTurno() == false && jugador3->getTurno() == false && jugador4->getTurno() == false) {
				Mostrar_Tablero();
				cout << "Jugador [1]" << endl;
				jugador1->MenuJugador();
				cout << endl;
				system("pause");
				system("cls");
				jugador1->setTurno(false);
				jugador2->setTurno(true);
				jugador3->setTurno(false);
				jugador4->setTurno(false);
			}

			if (jugador2->getTurno() == true && jugador1->getTurno() == false && jugador3->getTurno() == false && jugador4->getTurno() == false) {
				Mostrar_Tablero();
				cout << "Jugador [2]" << endl;
				jugador2->MenuJugador();
				cout << endl;
				system("pause");
				system("cls");
				jugador1->setTurno(true);
				jugador2->setTurno(false);
				jugador3->setTurno(false);
				jugador4->setTurno(false);
			}
		}
		else
		if (cantidadJugadores == 3) {
			if (jugador1->getTurno() == true && jugador2->getTurno() == false && jugador3->getTurno() == false && jugador4->getTurno() == false) {
				Mostrar_Tablero();
				cout << "Jugador [1]" << endl;
				jugador1->MenuJugador();
				cout << endl;
				system("pause");
				system("cls");
				jugador1->setTurno(false);
				jugador2->setTurno(true);
				jugador3->setTurno(false);
				jugador4->setTurno(false);
			}

			if (jugador2->getTurno() == true && jugador1->getTurno() == false && jugador3->getTurno() == false && jugador4->getTurno() == false) {
				Mostrar_Tablero();
				cout << "Jugador [2]" << endl;
				jugador2->MenuJugador();
				cout << endl;
				system("pause");
				system("cls");
				jugador1->setTurno(false);
				jugador2->setTurno(false);
				jugador3->setTurno(true);
				jugador4->setTurno(false);
			}

			if (jugador3->getTurno() == true && jugador1->getTurno() == false && jugador2->getTurno() == false && jugador4->getTurno() == false) {
				Mostrar_Tablero();
				cout << "Jugador [3]" << endl;
				jugador3->MenuJugador();
				cout << endl;
				system("pause");
				system("cls");
				jugador1->setTurno(true);
				jugador2->setTurno(false);
				jugador3->setTurno(false);
				jugador4->setTurno(false);
			}
		}
		else
		if (cantidadJugadores == 4) {
			
			if (jugador1->getTurno() == true && jugador2->getTurno() == false && jugador3->getTurno() == false && jugador4->getTurno() == false) {
				Mostrar_Tablero();
				cout << "Jugador [1]" << endl;
				jugador1->MenuJugador();
				cout << endl;
				system("pause");
				system("cls");
				jugador1->setTurno(false);
				jugador2->setTurno(true);
				jugador3->setTurno(false);
				jugador4->setTurno(false);
			}
			
			if ( jugador2->getTurno() == true && jugador1->getTurno() == false && jugador3->getTurno() == false && jugador4->getTurno() == false) {
				Mostrar_Tablero();
				cout << "Jugador [2]" << endl;
				jugador2->MenuJugador();
				cout << endl;
				system("pause");
				system("cls");
				jugador1->setTurno(false);
				jugador2->setTurno(false);
				jugador3->setTurno(true);
				jugador4->setTurno(false);
			}
			
			if (jugador3->getTurno() == true && jugador1->getTurno() == false && jugador2->getTurno() == false && jugador4->getTurno() == false) {
				Mostrar_Tablero();
				cout << "Jugador [3]" << endl;
				jugador3->MenuJugador();
				cout << endl;
				system("pause");
				system("cls");
				jugador1->setTurno(false);
				jugador2->setTurno(false);
				jugador3->setTurno(false);
				jugador4->setTurno(true);
			}
					
			if (jugador4->getTurno() == true && jugador1->getTurno() == false && jugador2->getTurno() == false && jugador3->getTurno() == false) {
				Mostrar_Tablero();
				cout << "Jugador [4]" << endl;
				jugador4->MenuJugador();
				cout << endl;
				system("pause");
				system("cls");
				jugador1->setTurno(true);
				jugador2->setTurno(false);
				jugador3->setTurno(false);
				jugador4->setTurno(false);
						
			}
		}
		else
			break;
	}
}