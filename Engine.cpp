#include "Engine.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "LineSegment.h"
#include<iostream>
#include<SDL.h>


//Inicjalizacja biblioteki graficznej
bool Engine::init(const std::string& windowtitle, int x, int y, int width, int height, bool Fullscreen, bool mouseOn, bool keyboardOn, int targetFPS,bool useDoubleBuffer) {

	useDoubleBuffer ? SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1) : SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 0);

	//zapisywanie bledow do pliku
	logFile.open("logFile.txt", std::ios::out | std::ios::app);
	if (!logFile) {
		std::cerr << "Nie mozna otworzyc pliku do zapisu bledow." << std::endl;
		return false;
	}
	
	
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) != 0) {
		logError("SDL Init error:" + std::string(SDL_GetError()));
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
		logError("SDL Window error:" + std::string(SDL_GetError()));
		return false;
	}

	screenSurface = SDL_GetWindowSurface(window);

	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));


	clearScreen(255, 255, 255);

	SDL_UpdateWindowSurface(window);

	isRunning = true;
	return true;
}


//Glowna petla gry
void Engine::mainLoop() {
	PrimitiveRenderer renderer(screenSurface);
	Point2D point1(100, 150);
	Point2D point2(400, 500);
	LineSegment line(point1, point2);
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


		//czyszczenie ekranu co klatke
		clearScreen(80, 80, 120);
		line.draw(renderer, 255, 0, 0);
		SDL_UpdateWindowSurface(window);
	
		
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)	//Czasomierz
			SDL_Delay(frameDelay - frameTime);
	}

	clean();
	
}

//czyszczenie ekranu
void Engine::clearScreen(Uint8 r, Uint8 g, Uint8 b) {
	if (!screenSurface) return;

	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, r, g, b));
}


//zapisywanie bledow do pliku
void Engine::logError(const std::string& message) {
	if (logFile.is_open()) {
		
		logFile << message << std::endl;
	
	}

	std::cerr << message << std::endl;

}



//zamkniecie gry
void Engine::clean() {
	if (screenSurface)
		screenSurface = nullptr;

	if (window)
		SDL_DestroyWindow(window);

	SDL_Quit();

	if (logFile.is_open()) {
		logFile << "Silnik poprawnie zamknieto. \n" << std::endl;
		logFile.close();
	}

	std::cout << "Silnik zamkniety, zasoby zwolnione" << std::endl;
}


