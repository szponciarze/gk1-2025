/**
* @file ShapeObject.h
* @brief Klasa bazowa dla wszystkich obiektów.
*/
#pragma once
#include"DrawableObject.h"
#include"TransformableObject.h"
/**
* @class ShapeObject
* @brief Abstrakcyjna klasa bazowa dla wszystkich obiektów
*/
class ShapeObject : public DrawableObject, public TransformableObject {
protected:
	/**
	* @brief Pozycja x i y obiektu.
	*/
	float m_x, m_y;
	/**
	* @brief Szerokoœæ i wysokoœæ obiektu.
	*/
	float m_w, m_h;

public:
	/**
	* @brief Konstruktor.
	* @param x Pozycja X.
	* @param y Pozycja Y.
	* @param w Szerokoœæ obiektu.
	* @param h Wysokoœæ obiektu.
	*/
	ShapeObject(float x=0, float y=0, float w=0, float h =0);
	/**
	* @brief Wirtualny destruktor.
	*/
	virtual ~ShapeObject();
	/**
	* @brief Rysuje obiekt.
	* @param renderer WskaŸnik na renderer SDL.
	*/
	virtual void draw(SDL_Renderer* renderer);
	/**
	* @brief Przesuwa obiekt.
	*
	* @param tx Przesuniêcie w pozycji X.
	* @param ty Przesuniêcie w pozycji Y.
	*/
	virtual void translate(float tx, float ty);
	/**
	* @brief Obraca obiekt.
	*
	* @param angle K¹t obrotu.
	*/
	virtual void rotate(float angle);
	/**
	* @brief Skaluje obiekt.
	*
	* @param sx Skala w pozycji X.
	* @param sy Skala w pozycji Y.
	*/
	virtual void scale(float sx, float sy);
	/**
	* @brief Sprawdza czy punkt znajduje siê wewen¹trz obiektu.
	*
	* @param px Pozycja X punktu.
	* @param py Pozycja Y punktu.
	*/
	virtual bool containsPoint(float px, float py);
	/**
	* @brief Zwraca X.
	* @return Wartoœæ X.
	*/
	float getX() const;
	/**
	* @brief Zwraca Y.
	* @return Wartoœæ Y.
	*/
	float getY() const;

};