#pragma once
#include "PrimitiveRenderer.h"

class Point2D {
private:
	int x;
	int y;
		
public:
	Point2D(int x, int y) :x(x), y(y) {}

	//Odczytanie wsp�rz�dnych punktu
	int getX() const { return x; }
	int getY() const { return y; }

	//Modyfikacja wsp�rz�dnych punktu
	void setX(int newX) { x = newX;}
	void setY(int newY) { y = newY;}

	//Rysuje punkt
	void draw(PrimitiveRenderer& renderer, Uint8 r, Uint8 g, Uint8 b) const {
		renderer.putPixel(x, y, r, g, b);
	}





};
