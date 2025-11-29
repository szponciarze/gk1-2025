/**
* @file EllipseFilled.h
* @brief Klasa reprezentuj¹ca elipsê.
*
* EllipseFilled dziedziczy po ShapeObject oraz UpdatableObject co umo¿liwia
* rotowanie, skalowanie itp. Zawiera kolor, œrodek elipsy,po³ osie i umo¿wliwa rysowanie.
*/
#pragma once
#include "ShapeObject.h"
#include "UpdatableObject.h"
#include <SDL.h>
/**
* @class EllipseFilled
* @brief Klasa reprezêtuj¹ca wype³nion¹ elipsê.
*
*/
class EllipseFilled : public ShapeObject, public UpdatableObject {
private:
    /**
    * @brief Œrodek wype³nionej.
    */
    float cx, cy;
    /**
    * @brief Pó³ osie wype³nionej elipsy.
    */
    float rx, ry;
    /**
    * @brief Rotacja wype³nionej elipsy.
    */
    float rotation;
    /**
    * @brief Kolor wype³nionej elipsy.
    */
    Uint8 r, g, b;

public:
    /**
    * @brief Konstruktor wype³nionej elipsy.
    *
    * @param cx Pozycja X œrodka.
    * @param cy Pozycja Y œrodka.
    * @param rx Pó³ oœ pozycji X.
    * @param ry Pó³ oœ pozycji Y.
    * @param r Kolor czerwony.
    * @param g Kolor zielony.
    * @param b Kolor niebieski.
    */
    EllipseFilled(float cx, float cy, float rx, float ry, Uint8 r, Uint8 g, Uint8 b);
    /**
    * @brief Przesuwa wype³nion¹ elipsê.
    *
    * @param dx Przesuniêcie w pozycji X.
    * @param dy Przesuniêcie w pozycji Y.
    */
    void translate(float dx, float dy) override;
    /**
    * @brief Obraca wype³nion¹ elipsê.
    *
    * @param angle K¹t obrotu.
    */
    void rotate(float angle) override;
    /**
    * @brief Skaluje wype³nion¹ elipsê.
    *
    * @param sx Skala w pozycji X.
    * @param sy Skala w pozycji Y.
    */
    void scale(float sx, float sy) override;
    /**
    * @brief Rysuje wype³nion¹ elipsê.
    *
    * @param WskaŸnik na renderer u¿ywany do rysowania.
    */
    void draw(SDL_Renderer* renderer) override;
    void update(float dt) override;
    /**
    * @brief Sprawdza czy punkt znajduje siê wewen¹trz wype³nionej elipsy.
    *
    * @param px Pozycja X punktu.
    * @param py Pozycja Y punktu.
    */
    bool containsPoint(float px, float py) override; 
};