/**
* @file RectangleFilled.h
* @brief Klasa reprezentuj¹ca prostok¹t.
*
* RectangleFilled dziedziczy po ShapeObject oraz UpdatableObject co umo¿liwia
* rotowanie, skalowanie itp. Zawiera kolor, szerokoœæ boku, wysokoœæ boku i umo¿wliwa rysowanie.
*/
#pragma once
#include"ShapeObject.h"
#include"UpdatableObject.h"
#include<SDL.h>
/**
* @class RectangleFilled
* @brief Klasa reprezêtuj¹ca wype³niony prostok¹t.
*
*/

class RectangleFilled : public ShapeObject, public UpdatableObject {
private:
    /**
    * @brief Szerokoœæ i wysokoœæ prostok¹ta.
    */
    float width, height;
    /**
    * @brief Pozycja X i Y.
    */
    float x, y;
    /**
    * @brief Rotacja wype³nioneg prostok¹ta.
    */
    float rotation;
    /**
    * @brief Kolor wype³nionego prostok¹ta.
    */
    Uint8 r, g, b;
public:
    /**
    * @brief Konstruktor wype³nionego prostok¹ta.
    *
    * @param x Pozycja X.
    * @param y Pozycja Y.
    * @param w Szerokoœæ prostok¹ta.
    * @param h Wysokoœæ prostok¹ta.
    * @param r Kolor czerwony.
    * @param g Kolor zielony.
    * @param b Kolor niebieski.
    */
    RectangleFilled(float x, float y, float w, float h, Uint8 r, Uint8 g, Uint8 b);
    /**
    * @brief Przesuwa wype³niony prostok¹t.
    *
    * @param dx Przesuniêcie w pozycji X.
    * @param dy Przesuniêcie w pozycji Y.
    */
    void translate(float dx, float dy) override;
    /**
    * @brief Obraca wype³niony prostok¹t.
    *
    * @param angle K¹t obrotu.
    */
    void rotate(float angle) override;
    /**
    * @brief Skaluje wype³niony prostok¹t.
    *
    * @param sx Skala w pozycji X.
    * @param sy Skala w pozycji Y.
    */
    void scale(float sx, float sy) override;
    /**
    * @brief Rysuje wype³niony prostok¹t.
    *
    * @param WskaŸnik na renderer u¿ywany do rysowania.
    */
    void draw(SDL_Renderer* renderer) override;
    void update(float dt) override;
    /**
    * @brief Sprawdza czy punkt znajduje siê wewen¹trz wype³nionego prostok¹ta.
    *
    * @param px Pozycja X punktu.
    * @param py Pozycja Y punktu.
    */
    bool containsPoint(float dx, float dy) override;
};