/**
* @file Point2D.h
* @brief Klasa reprezentuj¹ca punkt.
*/
#pragma once
#include "PrimitiveRenderer.h"
/**
* @class Point2D
* @brief Reprezentuje punkt..
*/
class Point2D {
private:
    /** 
    * @brief Pozycja X punktu. 
    */
	int x;
    /**
    * @brief Pozycja Y punktu.
    */
	int y;
		
public:
    /**
    * @brief Konstruktor tworz¹cy punkt.
    * @param x Pozycja X.
    * @param y Pozycja Y.
    */
	Point2D(int x, int y) :x(x), y(y) {}

    /**
    * @brief Zwraca wspó³rzêdn¹ X.
    * @return Aktualna wartoœæ X.
    */
	int getX() const { return x; }
    /**
    * @brief Zwraca wspó³rzêdn¹ Y.
    * @return Aktualna wartoœæ Y.
    */
	int getY() const { return y; }

    /**
    * @brief Ustawia wspó³rzêdn¹ X.
    */
	void setX(int newX) { x = newX;}
    /**
    * @brief Ustawia wspó³rzêdn¹ Y.
    */
	void setY(int newY) { y = newY;}
	/**
    * @brief Rysuje punkt.
    * @param renderer Odwo³anie do PrimitiveRenderer.
    * @param r Kolor czerwony.
    * @param g Kolor zielony.
    * @param b Kolor niebieski.
    */
	void draw(PrimitiveRenderer& renderer, Uint8 r, Uint8 g, Uint8 b) const {
		renderer.putPixel(x, y, r, g, b);
	}
    /**
    * @brief Przesuwa punkt.
    *
    * @param dx Przesuniêcie w pozycji X.
    * @param dy Przesuniêcie w pozycji Y.
    */
    void translate(float dx, float dy) {
        x += dx;
        y += dy;
    }
    /**
    * @brief Obraca punkt.
    * 
    * @param cx Pozycja X œrodka.
    * @param cy Pozycja Y œrodka.
    * @param angleDeg K¹t obrotu.
    *
    */
    void rotate(float cx, float cy, float angleDeg) {
        float rad = angleDeg * 3.14159265f / 180.0f;
        float tx = x - cx;
        float ty = y - cy;
        float xr = tx * cos(rad) - ty * sin(rad);
        float yr = tx * sin(rad) + ty * cos(rad);
        x = cx + xr;
        y = cy + yr;
    }
    /**
    * @brief Skaluje punkt.
    * @param cx Pozycja X œrodka.
    * @param cy Pozycja Y œrodka.
    * @param sx Skala w pozycji X.
    * @param sy Skala w pozycji Y.
    */
    void scale(float cx, float cy, float sx, float sy) {
        x = cx + (x - cx) * sx;
        y = cy + (y - cy) * sy;
    }
};
