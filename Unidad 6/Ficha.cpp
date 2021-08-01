#include "Ficha.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using namespace std;

Ficha::Ficha() {} //constructor vacio

Ficha::Ficha(char _f){ //constructor recibe el caracter que imprime en la ficha
	
	figura = _f;
}

void Ficha::setFicha(int _pos_x, int _pos_y) { //pide por teclado la posicion y asigna los valores en x e y
	bool posicion = true;
	
	while(posicion){
		
		if(kbhit()) { 
			int tecla=getch();
			
			switch(tecla)
			{
			case 49: 
				_pos_x = 0;
				_pos_y = 0;
				posicion = false;
				break;
			case 50: 
				_pos_x = 0;
				_pos_y = 1;
				posicion = false;
				break;
			case 51: 
				_pos_x = 0;
				_pos_y = 2;
				posicion = false;
				break;
			case 52: 
				_pos_x = 1;
				_pos_y = 0;
				posicion = false;
				break;
			case 53: 
				_pos_x = 1;
				_pos_y = 1;
				posicion = false;
				break;
			case 54: 
				_pos_x = 1;
				_pos_y = 2;
				posicion = false;
				break;
			case 55: 
				_pos_x = 2;
				_pos_y = 0;
				posicion = false;
				break;
			case 56: 
				_pos_x = 2;
				_pos_y = 1;
				posicion = false;
				break;
			case 57: 
				_pos_x = 2;
				_pos_y = 2;
				posicion = false;
				break;
			case 'z': case 'Z':
				cout<<"Gracias por jugar TA-TE-TI";
				exit(-1);
			}
			
		}
		pos_x = _pos_x;
		pos_y = _pos_y;
	}
}	

int Ficha::getFicha(int num) { //retorna los valores en x e y
	//'1' retorna posicion en x, cualqueir otro numero posicion en y
	if(num==1) {
		return pos_x;
	}
	
	return pos_y;
}

char Ficha::getFigura() { //retorna el valor que lleva la ficha
	return figura;
}
