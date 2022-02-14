#ifndef GAME_H
#define GAME_H
#include "Table.h"
#include "Piece.h"
#include "Palito.h"
#include "Cuadrado.h"
#include "EleRight.h"
#include "ZetaRight.h"
#include "ZetaLeft.h"
#include "EleLeft.h"
#include "Te.h"
#include <windows.h>
#include <ctime>

class game {
	
private:
	Piece * Pieza_movil = generate_piece(); //generamos y usando polimorfismo puede ser cuadrado, palito, te , etc
	Table * Tablero; // creamos el tablero
	int tetris[17][115]; //matriz para "TETRIS" en la pantalla de inicio
	bool game_over; 
	clock_t tempo;
	clock_t paso;
	int velocidad;
	int puntos_anterior;
	
public:
	game();
	void home_screen(); //definimos la matriz y la mostramos en la pantalla de inicio
	void hide_cursor(); //ocultamos el cursor
	void gameloop(); //bucle continuo del juego
	Piece* generate_piece(); //generamos una pieza y un color aleatorio
	void show_text(); //mostramos en pantalla todo lo que es texto
};
#endif
