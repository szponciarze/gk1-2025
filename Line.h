/**
* @file Line.h
* @brief Klasa reprezentuj¹ca liniê.
*
* Line dziedziczy po ShapeObject oraz UpdatableObject co umo¿liwia
* rotowanie, skalowanie itp. Zawiera kolor, zmienne pocz¹tkowego i koñcowego punktu oraz umo¿wliwa rysowanie.
*/
#pragma once
#include "ShapeObject.h"
#include "UpdatableObject.h"
/**
* @class Line
* @brief Klasa reprezêtuj¹ca liniê.
*
*/
class Line : public ShapeObject, public UpdatableObject {
private:
    /**
    * @brief Zmienne punktu pocz¹tkowego.
    */
    float x1, y1;
    /**
    * @brief Zmienne punktu koñcowego.
    */
    float x2, y2;
    /**
    * @brief Rotacja lini.
    */
    float rotation;
    /**
    * @brief Kolor lini.
    */
    Uint8 r, g, b;

public:
    /**
    * @brief Konstruktor lini.
    *
    * @param x1 Pozycja X punktu pocz¹tkowego.
    * @param y1 Pozycja Y punktu pocz¹tkowego.
    * @param x2 Pozycja X punktu koñcowego.
    * @param y2 Pozycja Y punktu koñcowego.
    * @param r Kolor czerwony.
    * @param g Kolor zielony.
    * @param b Kolor niebieski.
    */
    Line(float x1, float y1, float x2, float y2, Uint8 r, Uint8 g, Uint8 b);
    /**
    * @brief Przesuwa liniê.
    *
    * @param dx Przesuniêcie w pozycji X.
    * @param dy Przesuniêcie w pozycji Y.
    */
    void translate(float dx, float dy) override;
    /**
    * @brief Obraca liniê.
    *
    * @param angle K¹t obrotu.
    *
    */
    void rotate(float angle) override;
    /**
    * @brief Skaluje liniê.
    *
    * @param sx Skala w pozycji X.
    * @param sy Skala w pozycji Y.
    */
    void scale(float sx, float sy) override;
    /**
    * @brief Rysuje liniê.
    *
    * @param WskaŸnik na renderer u¿ywany do rysowania.
    */
    void draw(SDL_Renderer* renderer) override;
    void update(float dt) override;
    /**
    * @brief Sprawdza czy punkt znajduje siê na linii.
    *
    * @param dx Pozycja X punktu.
    * @param dy Pozycja Y punktu.
    */
    bool containsPoint(float dx, float dy) override;
};