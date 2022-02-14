#include "Game.h"
#include <conio2.h>
using namespace std;

game::game() {
	
	SetConsoleTitle("TETRIS"); //le ponemos un titulo a la ventana
	velocidad = 2;
	paso=CLOCKS_PER_SEC/velocidad;
	tempo=clock();
	game_over = false;
	
	Tablero = new Table(); //creamos el tablero
}

void game::home_screen() {
	
	for(int i = 0; i <17; i++){
		for(int j = 0; j<115; j++) {
			tetris[i][j]=32;
		}	
	}
	//letra T
	for(int i = 7; i < 21; i++) {
		tetris[7][i] = 178;
	}
	for(int i = 13; i <15; i++){
		for(int j = 8; j<16; j++) {
			tetris[j][i] = 178;
		}	
	}
	// letra E
	for(int i = 25; i < 38; i++) {
		tetris[7][i] = 178;
	}
	for(int i = 25; i < 38; i++) {
		tetris[11][i] = 178;
	}
	for(int i = 25; i < 38; i++) {
		tetris[15][i] = 178;
	}
	for(int i = 23; i <25; i++){
		for(int j = 7; j<16; j++) {
			tetris[j][i] = 178;
		}	
	}
	//letra T
	for(int i = 41; i < 55; i++) {
		tetris[7][i] = 178;
	}
	for(int i = 47; i <49; i++){
		for(int j = 8; j<16; j++) {
			tetris[j][i] = 178;
		}	
	}
	//letra R
	for(int i = 58; i <60; i++){
		for(int j = 7; j<16; j++) {
			tetris[j][i] = 178;
		}	
	}
	for(int i = 60; i < 73; i++) {
		tetris[7][i] = 178;
	}
	for(int i = 60; i < 73; i++) {
		tetris[11][i] = 178;
	}
	for(int i = 71; i <73; i++){
		for(int j = 8; j<11; j++) {
			tetris[j][i] = 178;
		}	
	}
	tetris[12][60] = 178; tetris[12][61] = 178;
	tetris[13][62] = 178; tetris[13][63] = 178;
	tetris[14][64] = 178; tetris[14][65] = 178;
	tetris[15][66] = 178; tetris[15][67] = 178;
	//letra I
	for(int i = 76; i < 90; i++) {
		tetris[7][i] = 178;
	}
	for(int i = 76; i < 90; i++) {
		tetris[15][i] = 178;
	}
	for(int i = 82; i <84; i++){
		for(int j = 8; j<15; j++) {
			tetris[j][i] = 178;
		}	
	}
	//letra S
	for(int i = 93; i < 107; i++) {
		tetris[7][i] = 178;
	}
	for(int i = 93; i < 107; i++) {
		tetris[11][i] = 178;
	}
	for(int i = 93; i < 107; i++) {
		tetris[15][i] = 178;
	}
	for(int i = 93; i <95; i++){
		for(int j = 8; j<11; j++) {
			tetris[j][i] = 178;
		}	
	}
	for(int i = 105; i <107; i++){
		for(int j = 12; j<15; j++) {
			tetris[j][i] = 178;
		}	
	}
	
	//IMPRIMIR
		for(int i = 0; i <17; i++){
			for(int j = 0; j<115; j++) {
				textcolor((rand()%15)+1);
				cout<<(char) tetris[i][j];
			}
			Sleep(150);
			cout<<endl;
		}
	//CREDITOS
	gotoxy(50, 20);
	textcolor(3);
	cout<<"By Joaqqinn"<<endl;
	textcolor(15);
	gotoxy(39, 22);
	system("PAUSE");
}
void game::hide_cursor() {
	
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;

	SetConsoleCursorInfo(hcon, &cursor);
	
}

void game::gameloop() {
	//MOSTRAMOS PANTALLA INICIO Y LIMPIAMOS PANTALLA
	home_screen();
	clrscr();
	
	//INICIO BUCLE DEL JUEGO
	while(!game_over) {
		
		hide_cursor();
		if(puntos_anterior != Tablero->get_points()) { //si los puntos cambian los volvemos a imprimir
			show_text();
		}
		Tablero->draw_table();
		Pieza_movil->delete_piece();
		if(tempo+paso<clock()) {                 //controlamos el tiempo para que sea siempre igual
			Pieza_movil->set_pos_y();
			tempo = clock();
		}
		Pieza_movil->move();
		Tablero->movement_legal(Pieza_movil);
		Pieza_movil->draw();
		if(Tablero->check_collision(Pieza_movil)) {  //comprobamos si hubo colision, si es verdadedor eliminamos la pieza y creamos una nueva
			Pieza_movil = NULL;
			Pieza_movil = generate_piece();
		}
		if(Tablero->check_full_row()) {  //comprobamos si se completo una linea si es verdadero aumentamos la velocidad
			velocidad++;
			paso=CLOCKS_PER_SEC/velocidad;
		}
		if(Tablero->check_gameover(Pieza_movil)) {  //si el gameover es verdadero terminamos el bucle y mostramos la pantalla final
			gotoxy(10, 11);
			clrscr();
			textcolor(4);
			gotoxy(55, 15);
			cout<<"GAMEOVER";
			gotoxy(40, 16);
			game_over = true;
		}
	
		Sleep(30);
	}

}

Piece* game::generate_piece() {
	
	int color = (rand()%5) + 1;
	int p = rand()%7;
	if (p == 0) return new Palito(color);
	if (p == 1) return new Cuadrado(color);
	if (p == 2) return new EleRight(color);
	if (p == 3) return new EleLeft(color);
	if (p == 4) return new ZetaRight(color);
	if (p == 5) return new ZetaLeft(color);
	if (p == 6) return new Te(color);
}

void game::show_text() {
	
	puntos_anterior = Tablero->get_points();
	//PUNTUACION
	textcolor(15);
	gotoxy(90,5);
	cout<<"SCORE";
	gotoxy(90,6);
	cout<<"  "<<Tablero->get_points();
	
	//TECLAS
	textcolor(15);
	gotoxy(10,5);
	cout<<"KEYS:";
	gotoxy(10,6);
	cout<<"Move Right: 'D'";
	gotoxy(10,7);
	cout<<"Move Left: 'A'";
	gotoxy(10,8);
	cout<<"Move Down: 'S'";
	gotoxy(10,9);
	cout<<"Rotation Right: 'L'";
	gotoxy(10,10);
	cout<<"Rotation Left: 'J'";
	gotoxy(10,11);
	cout<<"Exit: 'Esc'";
}


