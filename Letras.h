#ifndef LETRAS_H
#define LETRAS_H
#include <iostream>
#include <fstream>
#include <ctime>
#include "Tablero.h"
#include "Archivos.h"
using namespace std;
class _Letras: public _Tablero , public Diccionario{
public:
	string Fichas[7];
	int puntos;
	int puntos1;
	int total;
	int letra_ = 7;
	int PosI[7];
	int PosJ[7];
	int IJ = 0 , I = 0, Pos = 0, CONT = 0, Suma = 0, Suma1 = 0;
	int cantidad = 99;
	string letra;
	int valor;
	string Letra[99];
	int Valores[99];
	string CopiaLetras[99];
	int CopiaValores[99];
	int numeros[7];
	int ficha;
	int cant = 99;
	string Palabra;
	string Palabra1;
	string CopiaPalabra[7];
	string auxPalabra[7];
	int PonerPrimeraVez = 0;
	ifstream lee;
	//	ofstream Guarda;
public:
	void CrearCopia();
	bool repetida(int);
	void EliminaLetra(string&);
	void RepartirPrimeraVez();
	void RellenarFichas();
	void DevolverFichas();
	void Mostrar();
	void Verificar();
	void Comodin(string);
	void CambiarLetras(string &);
	void Poner();
	bool Esta(string &);
	bool InsertaPrimeraVez(int, int);
	bool Inserta(int, int);
	bool valida(int, int);
	void Menu();
	void Cambiar();
	
};
#endif // !LETRAS_H