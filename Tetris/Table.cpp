#include "Table.h"
#include <windows.h>
Table::Table() {
	
	pos_x = 40;
	pos_y = 30;
	puntos = 0;
		//COMPLETAMOS TABLERO Y TABLERO COLOR
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 30; j++) {
			tablero[i][j] = 0;
			tablero_color[i][j] = 0;
		}
	}	
	
}

void Table::draw_edges() {
	
	textcolor(15);
	for(int i = 40; i < 80; i++) {
		gotoxy(i, 1);
		cout<<(char)205;
		gotoxy(i, 30);
		cout<<(char)205;
	}
	for(int i = 2; i < 30; i++) {
		gotoxy(39, i);
		cout<<(char)186;
		gotoxy(80, i);
		cout<<(char)186;
	}
	gotoxy(39, 1);
	cout<<(char)201;
	gotoxy(80, 1);
	cout<<(char)187;
	gotoxy(39, 30);
	cout<<(char)200;
	gotoxy(80, 30);
	cout<<(char)188;
}

void Table::draw_table() {
	
	draw_edges();
	
	int fila = 1;
	
	for (int j = 29; j > 0; j--) {
		for (int i = 0; i < 40; i++) {
			if (tablero[i][j] == 219 || tablero[i][j] == 32) {
				textcolor(tablero_color[i][j]);
				gotoxy(pos_x+i, pos_y-fila);
				cout << (char)tablero[i][j];
			}
		}
		fila++;
	}	
}

void Table::movement_legal(Piece *P) {
//SE MUEVE Y ANTES DE DIBUJARLA COMPROBAMOS SI EL MOVIMIENTO ES LEGAL. SINO LO ES VOLVEMOS ATRAS
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5; i++) {
			if(P->position_occupied(i, j)) {
				if(tablero[(P->get_pos_x()+i)-pos_x][(P->get_pos_y()+j)] == 219) {
					P->set_pos_x();
				}
			}
		}
	}
}

bool Table::check_collision(Piece *P) {
	//NOS ANTICIPAMOS AL MOVIMIENTO PARA CHEQUEAR LA COLISION E IMPRIMIRLA LA PIEZA EN EL TABLERO
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5; i++) {
			if(P->position_occupied(i, j)) {
				if(tablero[(P->get_pos_x()+i)-pos_x][(P->get_pos_y()+j)+1] == 219 ||
				   (P->get_pos_y()+P->limit_lower()) == 29) {
					for (int i = 0; i < 5; i++) {
						for (int j = 0; j < 5; j++) {
							if(P->get_pieces(i, j) == 219) {
								tablero[P->get_pos_x()-pos_x+i][P->get_pos_y()+j] = P->get_pieces(i, j);
								tablero_color[P->get_pos_x()-pos_x+i][P->get_pos_y()+j] = P->get_color(i, j);
							}
						}
					}
					P->~Piece();
					return true;
				}
			}
		}
	}
	
	return false;
	
}

bool Table::check_full_row() {
	
	int contador = 0;
	//CHEQUEAMOS SI SE COMPLETO UNA LINEA
	for (int i = 0; i < 40; i++) {
		if(tablero[i][29] == 219) {
			contador ++;
		}
	}
    //ELIMINAMOS LA LINEA COMPLETADA
	if(contador == 40) {
		puntos++;
		for (int i = 0; i <40; i++) {
			tablero[i][29] = 32;
			tablero_color[i][29] = 0;
		}
		draw_table();
		move_row();
		clean_table();
		return true;
	}
	
	return false;
}

void Table::move_row() {
	
	for (int j = 29; j > 0; j--) {
		for (int i = 0; i < 40; i++) {
			tablero[i][j] = tablero[i][j-1];
			tablero_color[i][j] = tablero_color[i][j-1];
		}
	}	
}

void Table::clean_table() {
	
	int fila = 1;
	
	for (int j = 29; j > 0; j--) {
		for (int i = 0; i < 40; i++) {
			textcolor(0);
			gotoxy(pos_x+i, pos_y-fila);
			cout <<" ";
		}
		fila++;
	}	
}

bool Table::check_gameover(Piece *P) {
	
	for(int i = 0; i < 40; i++) {
		if(P->get_pos_y() == 2) {
			if (tablero[i][P->get_pos_y()+P->limit_lower()] == 219) {
				return true;
			}	
		}
	}
	return false;
}
