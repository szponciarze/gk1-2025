#include<iostream>
#include<SDL.h>
#include"Engine.h"


int main(int argc, char* args[]) {
	Engine engine;

	if (engine.init("Okno", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false, true, true, 144, 3)){	
		engine.mainLoop();
	}
	else {
		std::cerr << "Blad inicjalizacji silnika, sprawdz plik logFile.txt" << std::endl;
	}

	return 0;
}
