#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <iostream>
#include <fstream>
using namespace std;
struct Diccionario {
protected:
	int opcion, id = 0, contador = 86;
	char palabra[20];
	ifstream lee;
	string copias[86];
public:
	Diccionario();
	~Diccionario();
	void LlenaCopia();
	bool Existe(string);
};
//struct Letras {
//private:
//	int valor;
//	int valores[99];
//	int CopiaValores[99];
//	string CopiaLetras[99];
//	char letras[99];
//	char letra;
//	ifstream lee;
//	ofstream Guarda;
//public:
//	Letras();
//	~Letras();
//	void crearCopia();
//};
#endif // !ARCHIVOS_H
