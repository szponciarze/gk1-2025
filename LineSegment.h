#pragma once
#include "PrimitiveRenderer.h"
#include "Point2D.h"

class LineSegment {
private:
	Point2D first;
	Point2D last;

public:
	LineSegment(Point2D first, Point2D last):first(first),last(last){}

	//Odczytuje poszczeg�lne ko�ce odcinka
	Point2D getFirst() { return first; }
	Point2D getLast() { return last; }

	//Modyfikuje poszczeg�ne ko�ce odcinka
	void setFirst(Point2D newFirst) { first = newFirst; }
	void setLast(Point2D newLast) { last = newLast; }

	//Rysuje odcinek
	void draw(PrimitiveRenderer& renderer, Uint8 r, Uint8 g, Uint8 b) {
		renderer.incrementalAlgorithm(first.getX(), first.getY(), last.getX(), last.getY(), r, g, b);
	}

};
