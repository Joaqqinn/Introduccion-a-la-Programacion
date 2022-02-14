#include "Piece.h"

Piece::Piece() {
	pos_x = 58;
	pos_y = 2;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			color[i][j] = 0;
		}
	}	
}

Piece::~Piece() {}

int Piece::get_pieces(int i1, int j1) {
	
	return pieces[i1][j1];
}

void Piece::draw() {
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if(pieces[i][j] == 219) {
			textcolor(color[i][j]);
			gotoxy(pos_x+i, pos_y+j);
			cout << (char)pieces[i][j];
			}
		}
	}
}

void Piece::delete_piece() {
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if(pieces[i][j] == 219) {
				gotoxy(pos_x+i, pos_y+j);
				cout << " ";
			}
		}
	}
}

void Piece::move() {
	
	if (kbhit()) {
		char tecla = getch();
		
		switch (tecla)
		{
			
		case 'a': case 'A': //izquierda
			if(pos_x+limit_left() > 40) {
				pos_ant_x = pos_x;
				pos_x--;
			}
			
			break;
		case 'd': case 'D': //derecha
			if(pos_x+limit_right() < 79) {
				pos_ant_x = pos_x;
				pos_x++;	
			}
			
			break;
		case  's': case 'S'://abajo
			if(pos_y+limit_lower() < 29) {
				pos_y++;
			}
			
			break;
		case 'j': case 'J':
			rotation_left();
				
			break;
		case 'l': case 'L':
			rotation_right();
			
			break;
		case 27: //escape para salir
			exit(1);
		}
	}
}

void Piece::rotation_right() {
	
	int contador = 0; 
	// Verificamos cuantas posiciones ocupadas tiene la pieza
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if(pieces[i][j] == 219) {
				contador++;
			}
		}
	}	
	if (contador != 10) { //Limitamos la rotacion para el cuadrado
	int n = 5;
	int tmp;
	    for (int i = 0; i < n / 2; i++) {
			for (int j = i; j < n - i - 1; j++) {
			
				tmp                  = pieces[i][j];
				pieces[i][j]         = pieces[j][n-i-1];
			    pieces[j][n-i-1]     = pieces[n-i-1][n-j-1];
			    pieces[n-i-1][n-j-1] = pieces[n-j-1][i];
			    pieces[n-j-1][i]     = tmp;
		    }
	    }
    }
}

void Piece::rotation_left() {
	
	int contador = 0; 
	// Verificamos cuantas posiciones ocupadas tiene la pieza
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if(pieces[i][j] == 219) {
				contador++;
			}
		}
	}	
	if (contador != 10) { //Limitamos la rotacion para el cuadrado
		int n = 5;
		int tmp;
		for (int i = 0; i < n / 2; i++) {
			for (int j = i; j < n - i - 1; j++) {
				
				tmp                  = pieces[i][j];
				pieces[i][j]         = pieces[n-j-1][i];
				pieces[n-j-1][i]     = pieces[n-i-1][n-j-1];
				pieces[n-i-1][n-j-1] = pieces[j][n-i-1];
				pieces[j][n-i-1]     = tmp;
			}
		}
	}
}

int Piece::limit_lower() {
	
	int limit;
	
	for (int j = 4; j >= 0; j--) {
		for (int i = 0; i < 5; i++) {
			if (pieces[i][j] == 219) {
				
				limit = j;
				j = 0;
			}
		}
	}	
	return limit;
}

int Piece::limit_right() {
	
	for (int i = 4; i >= 0; i--) {
		for (int j = 0; j < 5; j++) {
			if (pieces[i][j] == 219) {
				
				return i;
			}
		}
	}	
	return 0;
}

int Piece::limit_left() {
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (pieces[i][j] == 219) {
				
				return i;
			}
		}
	}	
	return 0;
}

bool Piece::position_occupied(int _i, int _j) {
	
	int i = _i;
	int j = _j;
	if (pieces[i][j] == 219) {
		
		return true;
	}
	return false;
}

int Piece::get_color(int _i, int _j) {
	
	int i = _i;
	int j = _j;
	if (pieces[i][j] == 219) {
		
		return color[i][j];
	}
	return 0;
}
