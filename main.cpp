#include <iostream>
#include <conio.h>
#include "Scrabble.h"
#include "Letras.h"
using namespace std;
int main() {
	//_Letras L;
	//L.Menu();
	system("pause");
	bool opcion;
	short unsigned int contador = 0;
	do {
		Scrabble *nuevoScrabble = new Scrabble;
		if (contador == 0) {
			//nuevoScrabble->instrucciones();
			cout << "Primera vez 7u7" << endl;
		}
		nuevoScrabble->Jugar();
		nuevoScrabble = NULL;
		system("cls");
		cout << "NUEVO JUEGO [1] :D" << endl;
		cout << "SALIR [0] :(" << endl;
		cin >> opcion;
		contador++;
	} while (opcion != 0);
	cout << "VUELVE PRONTO ;)" << endl;
	system("pause");
	getchar();
	_getch();
}