#include "Jugador.h"
#include "Letras.h"
Jugador::Jugador(){
	turno = true;
}

Jugador::~Jugador(){}

void Jugador::setTurno(bool turno)
{
	this->turno = turno;
}

bool Jugador::getTurno()
{
	return turno;
}
void Jugador::MenuJugador()
{
	int opcion = 0;
	cout << "[1] Jugar" << endl;
	cout << "[2] Cambiar" << endl;
	cout << "[3] Diccionario" << endl;
	cout << "[4] Pasar" << endl;
	cout << "Digite la opcion que desea: "; cin >> opcion;
	switch (opcion)
	{
	case 1:
		Menu();
		break;
	case 2:
		Cambiar();
		break;
	case 3:
		cout << "Tranquilo si sirve :P" << endl;
		break;
	case 4:
		setTurno(false);
		break;
	default:
		break;
	}
	cout << endl;
}