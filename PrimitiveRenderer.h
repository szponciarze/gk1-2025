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

	void putPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b);

	void incrementalAlgorithm(int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b);

	// Rysuje pusty prostok�t
	void drawRect(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b);
	// Rysuje wype�niony prostok�t
	void fillRect(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b);
	// Rysuje puste ko�o
	void drawCircle(int cx, int cy, int radius, Uint8 r, Uint8 g, Uint8 b);
	//	Rysuje wype�nione ko�o
	void fillCircle(int cx, int cy, int radius, Uint8 r, Uint8 g, Uint8 b);
	// Rysuje pust� elips�
	void drawEllipse(int cx, int cy, int Rx, int Ry, Uint8 r, Uint8 g, Uint8 b);
	//Rysuje wype�nion� elips�
	void fillEllipse(int cx, int cy, int Rx, int Ry, Uint8 r, Uint8 g, Uint8 b);
	//Linie �amane
	void drawPolyline(const std::vector<Point2D>& points, Uint8 r, Uint8 g, Uint8 b, bool closed = false);
	void drawPolyline(const std::vector<LineSegment>& segments, Uint8 r, Uint8 g, Uint8 b);




};