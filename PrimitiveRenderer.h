#pragma once
#include<iostream>
#include<SDL.h>
#include<fstream>

class PrimitiveRenderer {

private:
	SDL_Surface* surface;

public:
	PrimitiveRenderer(SDL_Surface* surface) :surface(surface) {}
	void putPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b);
	void incrementalAlgorithm(int x1, int y1, int x2, int y2, Uint8 r, Uint8 b, Uint8 g);

};