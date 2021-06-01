#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
#include <string>
#include <sstream>
#include "Letras.h"
using namespace std;
class Jugador : public _Letras{
protected:
	bool turno;
	//string Fichas[7];
public:
	
	Jugador();
	~Jugador();
	void setTurno(bool);
	bool getTurno();
	void MenuJugador();
};
#endif // !JUGADOR_H