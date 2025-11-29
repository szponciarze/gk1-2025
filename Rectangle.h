/**
* @file Rectangle.h
* @brief Klasa reprezentuj¹ca prostok¹t.
*
* Rectangle dziedziczy po ShapeObject oraz UpdatableObject co umo¿liwia
* rotowanie, skalowanie itp. Zawiera kolor, szerokoœæ boku, wysokoœæ boku i umo¿wliwa rysowanie.
*/
#pragma once
#include"ShapeObject.h"
#include"UpdatableObject.h"
#include<SDL.h>
/**
* @class Rectangle
* @brief Klasa reprezêtuj¹ca prostok¹t.
*
*/
class Rectangle : public ShapeObject, public UpdatableObject {
protected:
    /**
    * @brief Szerokoœæ i wysokoœæ prostok¹ta.
    */
    float width, height;
    /**
    * @brief Rotacja prostok¹ta.
    */
    float rotation;
private:
    /**
    * @brief Kolor prostok¹ta.
    */
    Uint8 r,g,b;
public:
    /**
    * @brief Konstruktor prostok¹ta.
    *
    * @param x Pozycja X.
    * @param y Pozycja Y.
    * @param w Szerokoœæ prostok¹ta.
    * @param h Wysokoœæ prostok¹ta.
    * @param r Kolor czerwony.
    * @param g Kolor zielony.
    * @param b Kolor niebieski.
    */
    Rectangle(float x, float y, float w, float h, Uint8 r, Uint8 g, Uint8 b);
    /**
    * @brief Przesuwa prostok¹t.
    *
    * @param dx Przesuniêcie w pozycji X.
    * @param dy Przesuniêcie w pozycji Y.
    */
    void translate(float dx, float dy) override;
    /**
    * @brief Obraca prostok¹t.
    *
    * @param angle K¹t obrotu.
    */
    void rotate(float angle) override;
    /**
    * @brief Skaluje prostok¹t.
    *
    * @param sx Skala w pozycji X.
    * @param sy Skala w pozycji Y.
    */
    void scale(float sx, float sy) override;
    /**
    * @brief Rysuje prostok¹t.
    *
    * @param WskaŸnik na renderer u¿ywany do rysowania.
    */
    void draw(SDL_Renderer* renderer) override;
    void update(float dt) override;
};