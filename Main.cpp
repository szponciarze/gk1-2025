#include<iostream>
#include<SDL.h>
#include"Engine.h"


int main(int argc, char* args[]) {
	Engine engine;

	engine.init("Okno", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);



	return 0;
}
