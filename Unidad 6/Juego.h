#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h"

class Juego {
private:
	
	Tablero Mi_Tablero;
public:
	Juego();
	void play();
	void imprimirCabecera();
	void imprimirOpciones();
	bool checkGanador();
	void volveraJugar();
	
};

#endif

