#ifndef TABLE_H
#define TABLE_H
#include "Piece.h"
#include <iostream>
#include <conio2.h>

using namespace std;

class Table {
	
private:
	int tablero[40][30]; //matriz para almacenar las piezas que quedan en el tablero
	int tablero_color[40][30]; //matriz para almacenar los colores de las piezas que quedan en el tablero
	int pos_x, pos_y;
	int puntos;
	
public:
	Table();
	void draw_edges(); //dibujamos los bordes del tablero
	void draw_table(); //dibujamos el tablero
	void clean_table(); //limpiamos el tablero
	void movement_legal(Piece *P); //chequeamos si el movimiento que se hizo es legal
	bool check_collision(Piece *P); //chequeamos si hubo colision
	bool check_full_row(); //chequeamos si se completo una fila del tablero y la eliminamos
	void move_row(); //si eliminamos una linea porque se completo movemos todas 1 para abajo
	bool check_gameover(Piece *P); //chequeamos la condicion de perdida del juego
	int get_points() { return puntos; } //objetemos el valor de los puntos
};
#endif
