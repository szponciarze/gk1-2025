#include "Engine.h"
#include<iostream>
#include<SDL.h>

//Inicjalizacja biblioteki graficznej
bool Engine::init(const std::string& windowtitle, int x, int y, int width, int height, bool Fullscreen, bool mouseOn, bool keyboardOn, int targetFPS) {

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) != 0) {
		std::cerr << "SDL Init error:" << SDL_GetError() << std::endl;
		return false;
	}

	this->width = width;
	this->height = height;
	this->Fullscreen = Fullscreen;
	this->mouseOn = mouseOn;
	this->keyboardOn = keyboardOn;
	this->targetFPS = targetFPS;
	this->frameDelay = 1000 / targetFPS;

	Uint32 flags = Fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;
	window = SDL_CreateWindow(windowtitle.c_str(), x, y, width, height, flags);

	if (!window) {
		std::cerr << "SDL Window error:" << SDL_GetError() << std::endl;
		return false;
	}


	screenSurface = SDL_GetWindowSurface(window);

	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

	SDL_UpdateWindowSurface(window);


	isRunning = true;
	return true;
}

//Glowna petla gry
void Engine::mainLoop() {
	SDL_Event e;

	while (isRunning) {
		frameStart = SDL_GetTicks();




		while (SDL_PollEvent(&e)) {	//Obsluga zdarzen
			if (e.type == SDL_QUIT)
				isRunning = false;

			if (keyboardOn && e.type == SDL_KEYDOWN) {
				std::cout << "Nacisnieto klawisz: " << SDL_GetKeyName(e.key.keysym.sym) << std::endl;
			}


			if (mouseOn && e.type == SDL_MOUSEBUTTONDOWN) {
				std::cout << "Nacisnieto klawisz myszy w: (" << e.button.x << "," << e.button.y << ")" << std::endl;
			}




		}


		

		
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)	//Czasomierz
			SDL_Delay(frameDelay - frameTime);
	}

	//clean();
	//deinicjalizacja czyszczenie 
	// - do zaimplementowania
}


void Engine::clean() {
//do zaimplementowania
}


