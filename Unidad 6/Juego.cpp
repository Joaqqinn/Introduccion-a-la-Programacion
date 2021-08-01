#include "Juego.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

Juego::Juego(){} //constructor vacio

void Juego::imprimirCabecera() { //imprime la bienvenida al juego
	cout<<"BIENVENIDO AL JUEGO DE TA-TE-TI"<<endl;
	cout<<"Es un juego para 2 personas por turnos. El primer jugador en alinear 3 fichas iguales hace 'TA-TE-TI' y gano el juego"<<endl;
}

void Juego::imprimirOpciones() { //imprime las opciones de teclado
	cout<<"A1 presiona 1"<<endl;
	cout<<"B1 presiona 2"<<endl;
	cout<<"C1 presiona 3"<<endl;
	cout<<"A2 presiona 4"<<endl;
	cout<<"B2 presiona 5"<<endl;
	cout<<"C2 presiona 6"<<endl;
	cout<<"A3 presiona 7"<<endl;
	cout<<"B3 presiona 8"<<endl;
	cout<<"C3 presiona 9"<<endl;
	cout<<"'Z' si desea salir"<<endl<<endl;
}

bool Juego::checkGanador() { //verifica e imprime el ganador o si se empato en el juego
	if(Mi_Tablero.tateti('O')) {
		cout<<"El ganador es el Jugador 'O' "<<endl<<endl;
		return true;
	} else if(Mi_Tablero.tateti('X')) {
		cout<<"El ganador es el Jugador 'X' "<<endl<<endl;
		return true;
	} else if(Mi_Tablero.tablero_completo()){
		cout<<"Empate"<<endl;
		return true;
	}
	return 0;
}

void Juego::volveraJugar() { //ejecuta la variable de verificar ganador y pregunta si se desea volver a jugar
	if(checkGanador()) {
		bool j = true;
		cout<<"Desea volver a jugar?"<<endl;
		cout<<"'Z' si desea salir"<<endl;
		cout<<"'S' si desea volver a jugar"<<endl<<endl;
		
		while(j){
			
			
			if(kbhit()) { 
				int tecla=getch();
				
				switch(tecla)
				{
					
				case 's': case 'S':
					Mi_Tablero.reiniciarTablero();
					Mi_Tablero.mostrar_tablero(1);
					j = false;
					break;
					
				case 'z': case 'Z':
					cout<<"Gracias por jugar TA-TE-TI";
					exit(-1);
					break;
				}
				
			}
			
		}
	}
}

void Juego::play() { //gestiona los demas metodos
	imprimirCabecera();
	while(true) {
		Mi_Tablero.mostrar_tablero(1);
		volveraJugar();
		imprimirOpciones();
		Mi_Tablero.setFichaT('x');
		Mi_Tablero.mostrar_tablero(0);
		volveraJugar();
		imprimirOpciones();
		Mi_Tablero.setFichaT('o');
	}
}

