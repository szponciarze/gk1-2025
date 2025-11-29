/**
* @file CircleFilled.h
* @brief Klasa reprezentuj¹ca wype³niony okr¹g.
*
* CircleFilled dziedziczy po ShapeObject oraz UpdatableObject co umo¿liwia
* rotowanie, skalowanie itp. Zawiera kolor, promieñ i umo¿wliwa rysowanie.
*/
#pragma once
#include "ShapeObject.h"
#include "UpdatableObject.h"
#include <SDL.h>
/**
* @class CircleFilled
* @brief Klasa reprezêtuj¹ca wype³niony okr¹g.
*
*/

class CircleFilled : public ShapeObject, public UpdatableObject {
private:
    /**
    * @brief Promieñ wype³nionego okrêgu.
    */
    float radius;
    /**
    * @brief Kolor wype³nionego okrêgu.
    */
    Uint8 r, g, b;  

public:
    /**
    * @brief Konstruktor wype³nionego okrêgu.
    *
    * @param cx Pozycja X œrodka.
    * @param cy Pozycja Y œrodka.
    * @param radius Promieñ okrêgu.
    * @param r Kolor czerwony.
    * @param g Kolor zielony.
    * @param b Kolor niebieski.
    */
    CircleFilled(float cx, float cy, float radius, Uint8 r, Uint8 g, Uint8 b);
    /**
    * @brief Przesuwa wype³niony okr¹g.
    *
    * @param dx Przesuniêcie w pozycji X.
    * @param dy Przesuniêcie w pozycji Y.
    */
    void translate(float dx, float dy) override;
    /**
    * @brief Obraca wype³niony okr¹g.
    *
    * @param angle K¹t obrotu.
    *
    * Nie wykonuje ¿adnej operacji poniewa¿ okr¹g wygl¹da tak samo pod ka¿dym k¹tem.
    */
    void rotate(float angle) override;
    /**
    * @brief Skaluje wype³niony okr¹g.
    *
    * @param sx Skala w pozycji X.
    * @param sy Skala w pozycji Y.
    */
    void scale(float sx, float sy) override;
    /**
    * @brief Rysuje wype³niony okr¹g.
    *
    * @param WskaŸnik na renderer u¿ywany do rysowania.
    */
    void draw(SDL_Renderer* renderer) override;
    void update(float dt) override;
    /**
    * @brief Sprawdza czy punkt znajduje siê wewen¹trz okrêgu.
    *
    * @param px Pozycja X punktu.
    * @param py Pozycja Y punktu.
    */
    bool containsPoint(float px, float py) override;
};