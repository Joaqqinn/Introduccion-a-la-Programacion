#include "EleLeft.h"

EleLeft::EleLeft(int c) {
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			color[i][j] = c;
		}
	}	
	
	pieces[0][0] = 32; pieces[1][0] = 32; pieces[2][0] = 219; pieces[3][0] = 219; pieces[4][0] = 32;
	pieces[0][1] = 32; pieces[1][1] = 32; pieces[2][1] = 219; pieces[3][1] = 32; pieces[4][1] = 32;
	pieces[0][2] = 32; pieces[1][2] = 32; pieces[2][2] = 219; pieces[3][2] = 32; pieces[4][2] = 32;
	pieces[0][3] = 32; pieces[1][3] = 32; pieces[2][3] = 219; pieces[3][3] = 32; pieces[4][3] = 32;
	pieces[0][4] = 32; pieces[1][4] = 32; pieces[2][4] = 32; pieces[3][4] = 32; pieces[4][4] = 32;
}

EleLeft::~EleLeft() {}
