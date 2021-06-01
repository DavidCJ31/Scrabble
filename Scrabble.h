#ifndef SCRABBLE_H
#define SCRABBLE_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include "conio.h"
#include "windows.h"



#include "Jugador.h"
#include "Tablero.h"
using namespace std;
class Scrabble :public _Tablero {
private:
	Jugador *jugador1;
	Jugador *jugador2;
	Jugador *jugador3;
	Jugador *jugador4;
	
	bool bandera;
	int cantidadJugadores;
	string letra;
	int cantidad_letras;


	string instrucciones();
	
	int _cantidadJugadores();
	
	void inicializaJugadores();

	void MenuJugador();

	bool winner();
public:

	Scrabble();
	~Scrabble();
	
	void Jugar();
	void menu();
};
#endif // !SCRABBLE_H