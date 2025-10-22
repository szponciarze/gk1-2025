#pragma once
#include<iostream>
#include<SDL.h>

class Engine {
private:
	SDL_Window* window;
	SDL_Surface* screenSurface;
	bool Fullscreen;
	bool isRunning;
	int width;
	int height;
	bool mouseOn;
	bool keyboardOn;
	int targetFPS;
	Uint32 frameDelay;
	Uint32 frameStart;
	Uint32 frameTime;


public:
	//Inicjalizacja biblioteki graficznej
	bool init(const std::string& windowtitle, int x, int y, int width, int height, bool Fullscreen, bool mouseOn, bool keyboardOn, int targetFPS);

	//Glowna petla gry
	void mainLoop();

	//Deinicjalizacja biblioteki graficznej
	void clean();







};
