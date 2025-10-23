#pragma once
#include "PrimitiveRenderer.h"

class Point2D {
private:
	int x;
	int y;
		
public:
	Point2D(int x, int y) :x(x), y(y) {}

	//Odczytanie wspó³rzêdnych punktu
	int getX() { return x; }
	int getY() { return y; }

	//Modyfikacja wspó³rzêdnych punktu
	int setX(int newX) { x = newX;}
	int setY(int newY) { y = newY;}

	//Rysuje punkt
	void draw(PrimitiveRenderer& renderer, Uint8 r, Uint8 g, Uint8 b) {
		renderer.putPixel(x, y, r, g, b);
	}





};
