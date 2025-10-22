#include "Engine.h"
#include<iostream>
#include<SDL.h>


bool Engine::init(const std::string& windowtitle, int x, int y, int width, int height, bool Fullscreen) {

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) != 0) {
		std::cerr << "SDL Init error:" << SDL_GetError() << std::endl;
		return false;
	}

	Uint32 flags = Fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;
	window = SDL_CreateWindow(windowtitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);

	if (!window) {
		std::cerr << "SDL Window error:" << SDL_GetError() << std::endl;
		return false;
	}


	screenSurface = SDL_GetWindowSurface(window);

	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

	SDL_UpdateWindowSurface(window);


	SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }



	isRunning = true;
	return true;
}

