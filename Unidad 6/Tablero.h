#ifndef TABLERO_H
#define TABLERO_H
#include "Ficha.h"

class Tablero {
	
private:
	char mapa[3][3];
	Ficha Jugador_X;
	Ficha Jugador_Y;
public:
	Tablero();
	void setFichaT(char _ficha);
	void mostrar_tablero(int num);
	bool tateti(char _ficha);
	bool tablero_completo();
	void reiniciarTablero();
	
};

#endif

