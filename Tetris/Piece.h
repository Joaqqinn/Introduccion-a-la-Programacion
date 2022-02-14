#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <conio2.h>

using namespace std;

class Piece {
	
protected:
	int pieces[5][5]; //matriz para almacenar la pieza
	int color[5][5]; //matriz para almacenar el color de la pieza
	int pos_x, pos_y;
	int pos_ant_x;
	int _color;
	
public:
	Piece();
	~Piece();
	int get_pieces(int i1, int j1); //obtenemos los valores de cada ubicacion de la matriz
	int get_pos_x() { return pos_x; } //obtenemos la posicion en x
	int get_pos_y() { return pos_y; } //obtenemos la posicion en y
	int get_color(int _i, int _j); //obtenemos el color de cada posicion de la matriz
	void set_pos_x() { pos_x = pos_ant_x; } //modificamos la posicion en x
	void set_pos_y() { pos_y++; } //modificamos la posicion en y
	void draw(); //dibujamos la pieza
	void delete_piece(); //borramos la pieza 
	void move(); //gestionamos los controles para mover y rotar la pieza
	void rotation_right(); //rotar a la drecha
	void rotation_left(); //rotar a la izquierda
	int limit_lower(); //obtenemos en limite inferior de la pieza
	int limit_right(); //obtenemos en limite derecho de la pieza
	int limit_left(); //obtenemos el limite izquierdo de la pieza
	bool position_occupied(int _i, int _j); //obtenemos que posiciones de la pieza estan ocupadas
};
#endif
