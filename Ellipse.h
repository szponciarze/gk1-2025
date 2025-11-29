/**
* @file Ellipse.h
* @brief Klasa reprezentuj¹ca elipsê.
*
* Ellipse dziedziczy po ShapeObject oraz UpdatableObject co umo¿liwia
* rotowanie, skalowanie itp. Zawiera kolor, œrodek elipsy, pó³ osie i umo¿wliwa rysowanie.
*/
#pragma once
#include "ShapeObject.h"
#include "UpdatableObject.h"
#include <SDL.h>
/**
* @class Ellipse
* @brief Klasa reprezêtuj¹ca elipsê.
*
*/

class Ellipse : public ShapeObject, public UpdatableObject {
private:
    /**
    * @brief Œrodek elipsy.
    */
    float cx, cy; 
    /**
    * @brief Pó³ osie elipsy.
    */
    float rx, ry; 
    /**
    * @brief Rotacja elipsy.
    */
    float rotation;
    /**
    * @brief Kolor elipsy.
    */
    Uint8 r, g, b;

public:
    /**
    * @brief Konstruktor elipsy.
    *
    * @param cx Pozycja X œrodka.
    * @param cy Pozycja Y œrodka.
    * @param rx Pó³ oœ pozycji X.
    * @param ry Pó³ oœ pozycji Y.
    * @param r Kolor czerwony.
    * @param g Kolor zielony.
    * @param b Kolor niebieski.
    */
    Ellipse(float cx, float cy, float rx, float ry, Uint8 r, Uint8 g, Uint8 b);
    /**
    * @brief Przesuwa elipsê.
    *
    * @param dx Przesuniêcie w pozycji X.
    * @param dy Przesuniêcie w pozycji Y.
    */
    void translate(float dx, float dy) override;
    /**
    * @brief Obraca elipsê.
    *
    * @param angle K¹t obrotu.
    */
    void rotate(float angle) override;
    /**
    * @brief Skaluje elipsê.
    *
    * @param sx Skala w pozycji X.
    * @param sy Skala w pozycji Y.
    */
    void scale(float sx, float sy) override;
    /**
    * @brief Rysuje elipsê.
    *
    * @param WskaŸnik na renderer u¿ywany do rysowania.
    */
    void draw(SDL_Renderer* renderer) override;
    void update(float dt) override;
    /**
    * @brief Sprawdza czy punkt znajduje siê wewen¹trz elipsy.
    *
    * @param px Pozycja X punktu.
    * @param py Pozycja Y punktu.
    */
    bool containsPoint(float dx, float dy) override;
};