#pragma once
#include "PrimitiveRenderer.h"
#include "Point2D.h"



class LineSegment {
private:
	Point2D first;
	Point2D last;

public:
	LineSegment(const Point2D& p1, const Point2D& p2):first(p1),last(p2){}

	//Odczytuje poszczególne koñce odcinka
	Point2D getFirst() const   { return first; }
	Point2D getLast() const  { return last; }

	//Modyfikuje poszczegó³ne koñce odcinka
	void setFirst(Point2D newFirst) { first = newFirst; }
	void setLast(Point2D newLast) { last = newLast; }

	//Rysuje odcinek
	void draw(PrimitiveRenderer& renderer, Uint8 r, Uint8 g, Uint8 b) const {
		renderer.incrementalAlgorithm(first.getX(), first.getY(), last.getX(), last.getY(), r, g, b);
	}

};
