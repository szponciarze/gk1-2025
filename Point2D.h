#pragma once
#include "PrimitiveRenderer.h"

class Point2D {
private:
	int x;
	int y;
		
public:
	Point2D(int x, int y) :x(x), y(y) {}

	//Odczytanie wspolrzednych punktu
	int getX() const { return x; }
	int getY() const { return y; }

	//Modyfikacja wspolrzednych punktu
	void setX(int newX) { x = newX;}
	void setY(int newY) { y = newY;}

	//Rysuje punkt
	void draw(PrimitiveRenderer& renderer, Uint8 r, Uint8 g, Uint8 b) const {
		renderer.putPixel(x, y, r, g, b);
	}
	
    void translate(float dx, float dy) {
        x += dx;
        y += dy;
    }

    //obrot punktu woko³
    void rotate(float cx, float cy, float angleDeg) {
        float rad = angleDeg * 3.14159265f / 180.0f;
        float tx = x - cx;
        float ty = y - cy;
        float xr = tx * cos(rad) - ty * sin(rad);
        float yr = tx * sin(rad) + ty * cos(rad);
        x = cx + xr;
        y = cy + yr;
    }

    //skalowanie wzgledem srodka
    void scale(float cx, float cy, float sx, float sy) {
        x = cx + (x - cx) * sx;
        y = cy + (y - cy) * sy;
    }
};
