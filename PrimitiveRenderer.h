#pragma once
#include<iostream>
#include<SDL.h>
#include<fstream>

class PrimitiveRenderer {

private:
	SDL_Renderer* renderer;

public:
	PrimitiveRenderer(SDL_Renderer* renderer) :renderer(renderer) {}
	void putPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b);
	void incrementalAlgorithm(int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b);

};