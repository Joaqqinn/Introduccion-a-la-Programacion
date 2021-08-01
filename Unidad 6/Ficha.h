#ifndef FICHA_H
#define FICHA_H

class Ficha {
private:
	int pos_x, pos_y;
	char figura;
	
public:
	Ficha();
	Ficha(char _f);
	int getFicha(int num);
	char getFigura();
	void setFicha(int _pos_x, int _pos_y);
	
};

#endif

