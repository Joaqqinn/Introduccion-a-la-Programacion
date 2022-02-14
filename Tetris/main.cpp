#include "Game.h"
#include <ctime>
using namespace std;
	
	int main(int argc, char* argv[]) {
	
	srand(time(NULL)); //semilla tiempo

	game J;
	J.gameloop(); //iniciamos bucle del juego
	
	system("PAUSE");
	
	return 0;
}
