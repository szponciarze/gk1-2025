#pragma once
#include<iostream>
#include<SDL.h>
#include<fstream>
#include<vector>



class Engine {
private:
	SDL_Window* window;
	SDL_Renderer* render;
	std::vector<SDL_Texture*> buffers; // wektor tekstur pelniacych role buforow
	int currentBuffer = 0;
	int bufferCount = 2; // domyslnie podwojne buforowanie
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
	bool init(const std::string& windowtitle, int x, int y, int width, int height, bool Fullscreen, bool mouseOn, bool keyboardOn, int targetFPS, int bufferCount);
	
	//Glowna petla gry
	void mainLoop();

	//Czyszczenie ekranu do zadanego koloru
	void clearScreen(Uint8 r, Uint8 g, Uint8 b);

	//Logowanie komunikatow do pliku
	void logError(const std::string& message);


	//Deinicjalizacja biblioteki graficznej
	void clean();

	//rysowanie jednej klatki
	void renderFrame();
};

