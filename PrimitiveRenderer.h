#pragma once
#include<iostream>
#include<SDL.h>
#include<fstream>
#include<cmath>
#include <vector>


class Point2D;
class LineSegment;

class PrimitiveRenderer {

private:
	SDL_Renderer* renderer;

public:
	PrimitiveRenderer(SDL_Renderer* renderer) :renderer(renderer) {}

	bool getPixel(int x, int y, Uint8& r, Uint8& g, Uint8& b);

	void putPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b);

	void incrementalAlgorithm(int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b);

	// Rysuje pusty prostok¹t
	void drawRect(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b);
	// Rysuje wype³niony prostok¹t
	void fillRect(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b);
	// Rysuje puste ko³o
	void drawCircle(int cx, int cy, int radius, Uint8 r, Uint8 g, Uint8 b);
	//	Rysuje wype³nione ko³o
	void fillCircle(int cx, int cy, int radius, Uint8 r, Uint8 g, Uint8 b);
	// Rysuje pust¹ elipsê
	void drawEllipse(int cx, int cy, int Rx, int Ry, Uint8 r, Uint8 g, Uint8 b);
	//Rysuje wype³nion¹ elipsê
	void fillEllipse(int cx, int cy, int Rx, int Ry, Uint8 r, Uint8 g, Uint8 b);
	//Linie ³amane
	void drawPolyline(const std::vector<Point2D>& points, Uint8 r, Uint8 g, Uint8 b, bool closed = false);
	void drawPolyline(const std::vector<LineSegment>& segments, Uint8 r, Uint8 g, Uint8 b);
	//Metoda wypelniania kolorem flood fill
	void floodFill(SDL_Texture* targetTexture, int textureWidth, int textureHeight, int startX, int startY, Uint8 newR, Uint8 newG, Uint8 newB);
	//Metoda wypelniania kolorem border fill
	void borderFill(SDL_Texture* targetTexture, int textureWidth, int textureHeight, int startX, int startY,Uint8 borderR, Uint8 borderG, Uint8 borderB, Uint8 fillR, Uint8 fillG, Uint8 fillB);


};