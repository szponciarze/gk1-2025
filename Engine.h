#pragma once
#include<iostream>
#include<SDL.h>

class Engine {
private:
	SDL_Window* window;
	SDL_Surface* screenSurface;


public:
	//Inicjalizacja biblioteki graficznej
	bool init(const std::string& windowtitle, int x, int y, int width, int height, bool Fullscreen);
	//Deinicjalizacja biblioteki graficznej
	void clean();
	//Glowna petla gry
	void mainLoop();


	bool Fullscreen;
	bool isRunning;
	int width;
	int height;




};
