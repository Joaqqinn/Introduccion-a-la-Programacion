#include "Tablero.h"
#include <iostream>
using namespace std;

Tablero::Tablero() { //constructor inicializa el array mapa
	for(int i = 0; i<3; i++) {
		for(int j = 0; j<3; j++) {
			mapa[i][j] = ' ';
		}
	}
}

void Tablero::setFichaT(char _ficha) { //pide la posicion y el valor a la clase ficha y controla que no este ocupada la posicion
	Ficha Jugador_X('X');
	Ficha Jugador_O('O');
	bool p = true;
	
	if(_ficha == 'x') {
		Jugador_X.setFicha(0,0);
		while(p) {
			if(mapa[Jugador_X.getFicha(1)][Jugador_X.getFicha(0)] == 'X') {
				Jugador_X.setFicha(0,0);
			}
			if(mapa[Jugador_X.getFicha(1)][Jugador_X.getFicha(0)] == ' ') {
				p = false;
			}
		}
		mapa[Jugador_X.getFicha(1)][Jugador_X.getFicha(0)] = Jugador_X.getFigura();
	}
	
	if(_ficha == 'o') {
		Jugador_O.setFicha(0,0);
		while(p) {
			if(mapa[Jugador_O.getFicha(1)][Jugador_O.getFicha(0)] == 'O') {
				Jugador_O.setFicha(0,0);
			}
			if(mapa[Jugador_O.getFicha(1)][Jugador_O.getFicha(0)] == ' ') {
				p = false;
			}
		}
		mapa[Jugador_O.getFicha(1)][Jugador_O.getFicha(0)] = Jugador_O.getFigura();
	}
}	

void Tablero::mostrar_tablero(int num) { //muestra a que jugador le toca jugar e imprime el tablero
	Ficha Jugador_X('X');
	Ficha Jugador_O('O');
	if(num == 1) {
		cout<<"Turno del jugador numero:  "<<Jugador_X.getFigura()<<endl; 
	} else {
		cout<<"Turno del jugador numero:  "<<Jugador_O.getFigura()<<endl; 
	}
	cout<<endl<<"     A   B   C  "<<endl;
	cout<<"   -------------"<<endl;
	for(int i = 0; i<3; i++) {
		cout<<" "<<i+1;
		for(int j = 0; j<3; j++) {
			cout<<" | "<<mapa[i][j];
		}
		cout<<" | "<<endl;
		cout<<"   -------------"<<endl;	
	}
}

bool Tablero::tateti(char _ficha) { //verifica si se dio tateti
	for(int j = 0; j<3; j++) {
		int i = 0;
		if((mapa[i][j]==_ficha) && (mapa[i+1][j]==_ficha) && (mapa[i+2][j]==_ficha)) {
			cout<<"!TA-TE-TI!"<<endl;
			return true;
		}
	}		
	for(int i = 0; i<3; i++) {
		int j = 0;			
		if((mapa[i][j]==_ficha) && (mapa[i][j+1]==_ficha) && (mapa[i][j+2]==_ficha)) {
			cout<<"!TA-TE-TI!"<<endl;
			return true;
		}
	}	
	if((mapa[0][0]==_ficha) && (mapa[1][1]==_ficha) && (mapa[2][2]==_ficha)) {
		cout<<"!TA-TE-TI!"<<endl;
		return true;
	} if((mapa[2][0]==_ficha) && (mapa[1][1]==_ficha) && (mapa[0][2]==_ficha)) {
		cout<<"!TA-TE-TI!"<<endl;
		return true;
	}
	return false;
}	

bool Tablero::tablero_completo() { //verifica si el tablero se completo
	int contador = 0;
	for(int i = 0; i<3; i++) {
		for(int j = 0; j<3; j++) {
			if(mapa[i][j] != ' ') {
				contador++;
			} 
		}
	}
	if(contador == 9) {
		return true;
	}
	return false;
}

void Tablero::reiniciarTablero() { //reinicia los valores del array mapa para comenzar de nuevo el juego
	for(int i = 0; i<3; i++) {
		for(int j = 0; j<3; j++) {
			mapa[i][j] = ' ';
		}
	}
}


