#include "Archivos.h"

Diccionario::Diccionario() {}

Diccionario::~Diccionario() {}

void Diccionario::LlenaCopia()
{
	lee.open("Diccionario.dat", ios::in | ios::binary);
	lee >> palabra;
	int _contador = 1;
	while (!lee.eof()) {
		if (id == _contador) {
			copias[_contador] = palabra;
		}
		lee >> palabra;
		contador++;
	}
	lee.close();
	cin.get();
}

bool Diccionario::Existe(string _palabra)
{
	for (int i = 0; i < contador; i++) {
		if (copias[i] == _palabra) {
			return true;
		}
	}
	return false;
}

//Letras::Letras(){}
//
//Letras::~Letras(){}
//
//void Letras::crearCopia() {
//	lee.open("Letras.dat", ios::in | ios::binary);
//	lee >> letra;
//	int _contador = 1;
//	while (!lee.eof()) {
//		lee >> valor;
//		letras[_contador] = letra;
//		CopiaLetras[_contador] = letra;
//		valores[_contador] = valor;
//		CopiaValores[_contador] = valor;
//		lee >> letra;
//		_contador++;
//	}
//	lee.close();
//	cin.get();
//
//	cout << "\nMuestra las letras en el vector" << endl;
//	for (int i = 0; i < 99; i++) {
//		cout << "[" << letras[i] << "]";
//	}
//	cout << "\nMuestra los valores en el vector" << endl;
//	for (int i = 0; i < 99; i++) {
//		cout << "[" << valores[i] << "]";
//	}
//}