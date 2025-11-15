#pragma once
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include<cmath>



class LineSegment {
private:
	Point2D first;
	Point2D last;

public:
	LineSegment(const Point2D& p1, const Point2D& p2):first(p1),last(p2){}

	//Odczytuje poszczegolne konce odcinka
	Point2D getFirst() const   { return first; }
	Point2D getLast() const  { return last; }

	//Modyfikuje poszczegolne konce odcinka
	void setFirst(Point2D newFirst) { first = newFirst; }
	void setLast(Point2D newLast) { last = newLast; }

	//Rysuje odcinek
	void draw(PrimitiveRenderer& renderer, Uint8 r, Uint8 g, Uint8 b) const {
		renderer.incrementalAlgorithm(first.getX(), first.getY(), last.getX(), last.getY(), r, g, b);
	}

    //dlugosc odcinka
    float length() const {
        float dx = last.getX() - first.getX();
        float dy = last.getY() - first.getY();
        return sqrt(dx * dx + dy * dy);
    }

    //przesuwanie odcinka
    void translate(float dx, float dy) {
        first.translate(dx, dy);
        last.translate(dx, dy);
    }

    //obrot odcinka wokol punktu
    void rotate(float cx, float cy, float angleDeg) {
        first.rotate(cx, cy, angleDeg);
        last.rotate(cx, cy, angleDeg);
    }

    //skalowanie odcinka wzgledem punktu
    void scale(float cx, float cy, float sx, float sy) {
        first.scale(cx, cy, sx, sy);
        last.scale(cx, cy, sx, sy);
    }

};
