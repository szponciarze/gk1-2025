/**
* @file TransformableObject.h
* @brief Klasa bazowa umo¿liwiaj¹cych transformacje.
*/
#pragma once
#include "GameObject.h"
/**
* @class TransformableObject
* @brief Abstrakcyjna klasa bazowa dla obiektów
*/
class TransformableObject : public virtual GameObject {
public:
	/**
	* @brief Domyœlny konstruktor.
	*/
	TransformableObject();
	/**
	* @brief Wirtualny destruktor.
	*/
	virtual ~TransformableObject();
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
};