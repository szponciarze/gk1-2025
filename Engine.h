#pragma once
#include<iostream>
#include<SDL.h>
#include<fstream>



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
	
	std::ofstream logFile;

public:
	//Inicjalizacja biblioteki graficznej
	bool init(const std::string& windowtitle, int x, int y, int width, int height, bool Fullscreen, bool mouseOn, bool keyboardOn, int targetFPS,bool useDoubleBuffer);

	//Glowna petla gry
	void mainLoop();

	//Czyszczenie ekranu do zadanego koloru
	void clearScreen(Uint8 r, Uint8 g, Uint8 b);

	//Logowanie komunikatow do pliku
	void logError(const std::string& message);
	

	//Deinicjalizacja biblioteki graficznej
	void clean();
};

