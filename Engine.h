#pragma once
#include<iostream>
#include<SDL.h>

class Engine {
private:
	SDL_Window* window;
	SDL_Surface* screenSurface;


public:

	bool init(const std::string& windowtitle, int x, int y, int width, int height, bool Fullscreen);
	void clean();
	void run();


	bool Fullscreen;
	bool isRunning;
	int width;
	int height;




};
