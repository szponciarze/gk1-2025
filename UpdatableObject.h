/**
 * @file UpdatableObject.h
 * @brief Deklaracja klasy obiektów gry obs³uguj¹cych logikê aktualizacji.
*/
#pragma once
#include "GameObject.h"
/**
 * @class UpdatableObject
 * @brief Klasa bazowa dla wszystkich obiektów gry, które mog¹ byæ aktualizowane w logice gry.
 */
class UpdatableObject : public virtual GameObject {
public:

	/**
	* @brief Domyœlny konstruktor.
	*/
	UpdatableObject();
	/**
	* @brief Wirtualny destruktor.
	*/
	virtual ~UpdatableObject();
	/**
	 * @brief Metoda aktualizuj¹ca obiekt.
	 * @param dt Czas trwania jednej klatki w sekundach, wykorzystywany do synchronizacji ruchu/animacji.
	 */
	virtual void update(float dt);
};