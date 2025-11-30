/**
* @file AnimatedObject.h
* @brief Interfejs dla obiektów animowanych.
*
* AnimatedObject dziedziczy po UpdatableObject, co pozwala na integracjê
* z g³ówn¹ pêtl¹ silnika i aktualizacjê stanu animacji w czasie.
*/
#pragma once
#include "UpdatableObject.h"
/**
* @class AnimatedObject
* @brief Klasa bazowa (interfejs) dla obiektów posiadaj¹cych animacjê.
*
*/
class AnimatedObject : public virtual UpdatableObject {
public:
    /**
   * @brief Wirtualny destruktor domyœlny.
   */
    virtual ~AnimatedObject() = default;

    /**
  * @brief Wykonuje krok animacji.
  *
  * Metoda czysto wirtualna. Przekazywany czas (dt) zapewnia p³ynnoœæ
  * animacji niezale¿n¹ od liczby klatek na sekundê (FPS).
  *
  * @param dt Czas, który up³yn¹³ od ostatniej klatki (delta time).
  */
    virtual void animate(float dt) = 0;
};