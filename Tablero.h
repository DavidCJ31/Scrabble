#ifndef TABLERO_H
#define TABLERO_H
const int _cantidad = 15;
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
class _Tablero {

public:
	string Tablero[_cantidad][_cantidad];
	_Tablero();
	void SetColor(int);
	void LlenaTablero();//LLENO
	void Mostrar_Tablero();//MODIFICABLE
};
#endif // !TABLERO_H
