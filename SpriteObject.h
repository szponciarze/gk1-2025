/**
* @file SpriteObject.h
* @brief Klasa ³¹cz¹ca mo¿liwoœæ rysowania bitmap z logik¹ animacji.
*
* SpriteObject dziedziczy po BitmapObject oraz AnimatedObject, co pozwala na
* wyœwietlanie sekwencji grafik (animacji) w okreœlonym czasie.
*/
#pragma once

#include "BitmapObject.h"
#include "AnimatedObject.h"
#include <map>
/**
* @class SpriteObject
* @brief Klasa reprezentuj¹ca animowany obiekt typu Sprite.
*
*/

class SpriteObject : public BitmapObject, public AnimatedObject {
protected:
    /**
   * @brief Mapa przechowywuj¹ca definicje animacji.
   *
   * Kluczem jest nazwa animacji, a wartoœci¹ wektor identyfikatorów bitmap.
   */
    std::map<std::string, std::vector<std::string>> m_animations;
    /**
    * @brief Nazwa aktualnie odtwarzanej animacji.
    */
    std::string m_currentAnimation;
    /**
   * @brief Prêdkoœæ odtwarzania animacji.
   */
    float m_animSpeed; 
    /**
   * @brief Licznik czasu do kontroli zmiany klatek animacji.
   */
    float m_animTimer; 

public:
    /**
* @brief Konstruktor obiektu Sprite.
*
* Inicjalizuje pozycjê, wymiary oraz prêdkoœæ animacji. Bitmapy dodaje siê póŸniej.
*
* @param x Pozycja X.
* @param y Pozycja Y.
* @param w Szerokoœæ.
* @param h Wysokoœæ.
* @param animSpeed Prêdkoœæ animacji (domyœlnie 10.0f).
*/
    SpriteObject(float x, float y, float w, float h, float animSpeed = 10.0f);
    /**
 * @brief Dodaje now¹ definicjê animacji.
 *
 * @param name Unikalna nazwa animacji.
 * @param bitmapIDs Wektor zawieraj¹cy identyfikatory bitmap (klatek) dla tej animacji.
 */
   
    void addAnimation(const std::string& name, const std::vector<std::string>& bitmapIDs);
    /**
   * @brief Ustawia aktualnie odtwarzan¹ animacjê.
   *
   * @param name Nazwa animacji do ustawienia.
   */

    void setAnimation(const std::string& name);
    /**
   * @brief Aktualizuje stan obiektu.
   *
   * @param dt Czas, który up³yn¹³ od ostatniej klatki (delta time).
   */
    void update(float dt) override;
    /**
 * @brief Przetwarza logikê animacji.
 *
 * Odpowiada za zmianê klatek w zale¿noœci od up³ywu czasu.
 *
 * @param dt Czas, który up³yn¹³ od ostatniej klatki (delta time).
 */
    void animate(float dt) override;
};
