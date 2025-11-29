/**
* @file LineSegment.h
* @brief Klasa reprezentuj¹ca liniê.
*/
#pragma once
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include<cmath>
/**
* @class LineSegment
* @brief Reprezentuje liniê.
*/
class LineSegment {
private:
    /**
    * @brief Punkt pocz¹tkowy.
    */
	Point2D first;
    /**
    * @brief Punkt koñcowy.
    */
	Point2D last;

public:
    /**
    * @brief Konstruktor tworz¹cy liniê.
    * @param p1 Punkt pocz¹tkowy.
    * @param p2 Punkt koñcowy.
    */
	LineSegment(const Point2D& p1, const Point2D& p2):first(p1),last(p2){}

    /**
    * @brief Zwraca punkt pocz¹tkowy.
    * @return Aktualna wartoœæ punktu pocz¹tkowego.
    */
	Point2D getFirst() const   { return first; }
    /**
    * @brief Zwraca punkt koñcowy.
    * @return Aktualna wartoœæ punktu koñcowego.
    */
	Point2D getLast() const  { return last; }
    /**
    * @brief Ustawia punkt pocz¹tkowy.
    */
	void setFirst(Point2D newFirst) { first = newFirst; }
    /**
    * @brief Ustawia punkt koñcowy.
    */
	void setLast(Point2D newLast) { last = newLast; }
    /**
    * @brief Rysuje liniê.
    * @param renderer Odwo³anie do PrimitiveRenderer.
    * @param r Kolor czerwony.
    * @param g Kolor zielony.
    * @param b Kolor niebieski.
    */
	void draw(PrimitiveRenderer& renderer, Uint8 r, Uint8 g, Uint8 b) const {
		renderer.incrementalAlgorithm(first.getX(), first.getY(), last.getX(), last.getY(), r, g, b);
	}

    /**
    * @brief D³ugoœæ odcinka.
    */
    float length() const {
        float dx = last.getX() - first.getX();
        float dy = last.getY() - first.getY();
        return sqrt(dx * dx + dy * dy);
    }
    /**
    * @brief Przesuwa liniê.
    *
    * @param dx Przesuniêcie w pozycji X.
    * @param dy Przesuniêcie w pozycji Y.
    */
    void translate(float dx, float dy) {
        first.translate(dx, dy);
        last.translate(dx, dy);
    }
    /**
    * @brief Obraca liniê.
    *
    * @param cx Pozycja X.
    * @param cy Pozycja Y.
    * @param angleDeg K¹t obrotu.
    *
    */
    void rotate(float cx, float cy, float angleDeg) {
        first.rotate(cx, cy, angleDeg);
        last.rotate(cx, cy, angleDeg);
    }

    /**
    * @brief Skaluje liniê.
    * @param cx Pozycja X.
    * @param cy Pozycja Y.
    * @param sx Skala w pozycji X.
    * @param sy Skala w pozycji Y.
    */
    void scale(float cx, float cy, float sx, float sy) {
        first.scale(cx, cy, sx, sy);
        last.scale(cx, cy, sx, sy);
    }

};
