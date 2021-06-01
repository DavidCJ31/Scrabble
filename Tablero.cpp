#include "Tablero.h"
_Tablero::_Tablero() {
	//Llenado del tablero

	for (int i = 0; i < _cantidad; i++) {
		for (int j = 0; j < _cantidad; j++) {
			Tablero[i][j] = "";
		}
	}

}

void _Tablero::SetColor(int ForgC)
{
	WORD wColor;
	//This handle is needed to get the current background attribute

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	//csbi is used for wAttributes word

	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//To mask out all but the background attribute, and to add the color
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	//return;
}

void _Tablero::LlenaTablero() {

	for (int i = 0; i < _cantidad; i++) {

		for (int a = 0; a < _cantidad; a++) {
			if (a == (_cantidad - 1) - i) {
				Tablero[i][a] = "DP";
			}
			for (int j = 0; j < _cantidad; j++) {
				if (i == j) {
					Tablero[i][j] = "DP";
				}
			}
		}

		for (int j = 0; j < _cantidad; j++) {

			if ((i == 3 && (j == 0 || j == 7 || j == 14)) || (i == 2 && (j == 6 || j == 8)) || (i == 6 && (j == 2 || j == 6 || j == 8 || j == 12)) || (i == 8 && (j == 2 || j == 6 || j == 8 || j == 12)) || (i == 7 && (j == 3 || j == 11)) || (i == 11 && (j == 0 || j == 7 || j == 14)) || (i == 12 && (j == 6 || j == 8))) {
				Tablero[i][j] = "DL";
			}

			if (i == _cantidad / 2 && j == _cantidad / 2) {
				Tablero[i][j] = "**";
			}

			Tablero[0][0] = "TP";
			Tablero[0][7] = "TP";
			Tablero[0][14] = "TP";
			Tablero[0][3] = "DL";
			Tablero[0][11] = "DL";
			Tablero[1][5] = "TL";
			Tablero[1][9] = "TL";
			Tablero[5][1] = "TL";
			Tablero[5][5] = "TL";
			Tablero[5][9] = "TL";
			Tablero[5][13] = "TL";
			Tablero[7][0] = "TP";
			Tablero[7][14] = "TP";
			Tablero[9][1] = "TL";
			Tablero[9][13] = "TL";
			Tablero[9][5] = "TL";
			Tablero[9][9] = "TL";
			Tablero[13][5] = "TL";
			Tablero[13][9] = "TL";
			Tablero[14][0] = "TP";
			Tablero[14][7] = "TP";
			Tablero[14][14] = "TP";
			Tablero[14][3] = "DL";
			Tablero[14][11] = "DL";

		}
	}
}

void _Tablero::Mostrar_Tablero() {
	//CAMBIAR
	system("color 3F"); // 3 // 2 // 4
	cout << endl;
	for (int i = 0; i < _cantidad; i++) {
		if (i < 10) {
			cout << "    " << i;
		}
		else {
			cout << "   " << i;
		}
	}
	
	cout << "\n   ============================================================================";
	for (int i = 0; i < _cantidad; i++) {
		if (i > 9) {
			cout << endl << i << " | ";
		}
		else {
			cout << endl << i << "  | ";
		}
		for (int j = 0; j < _cantidad; j++) {
			if (Tablero[i][j] == "**") {
				SetColor(14);
				cout << Tablero[i][j];
				SetColor(15);
				cout << " | ";
			}
			else{
				if (Tablero[i][j] == "TL" || Tablero[i][j] == "DL" || Tablero[i][j] == "DP" || Tablero[i][j] == "TP" || Tablero[i][j] == "RR" || Tablero[i][j] == "CH" || Tablero[i][j] == "LL") {
					if (Tablero[i][j] == "TL") {
						SetColor(9);
					}
					if (Tablero[i][j] == "TP") {
						SetColor(4);
					}
					if (Tablero[i][j] == "DL") {
						SetColor(11);
					}
					if (Tablero[i][j] == "DP") {
						SetColor(12);
					}
					cout << Tablero[i][j];
					SetColor(15);
					cout << " | ";
				}
				else {
					if (Tablero[i][j].size() > 2) {
						cout << Tablero[i][j] << "  | ";
					}
					else {
						cout << Tablero[i][j] << "   | ";
					}
				}
			}
			if (j == _cantidad - 1) {
				//cout << "\n******************************************************************************";
				cout << "\n   ============================================================================";
			}
		}
	}
	cout << endl;
}