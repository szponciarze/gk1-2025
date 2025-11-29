/**
* @file Polyline.h
* @brief Klasa reprezentuj¹ca liniê ³aman¹.
*
* Polyline dziedziczy po ShapeObject oraz UpdatableObject co umo¿liwia
* rotowanie, skalowanie itp. Zawiera kolor, oraz wektor z punktami i umo¿wliwa rysowanie.
*/
#pragma once
#include "ShapeObject.h"
#include "UpdatableObject.h"
#include <vector>
/**
* @class Polyline
* @brief Klasa reprezêtuj¹ca liniê ³aman¹.
*
*/
class Polyline : public ShapeObject, public UpdatableObject {
private:
    /**
    * @brief Wektor zawieraj¹cy punkty.
    */
    std::vector<SDL_FPoint> points;
    /**
    * @brief Kolor lini ³amanej.
    */
    Uint8 r, g, b;

public:
    /**
    * @brief Konstruktor lini ³amanej.
    * @param pts Punkty linii.
    * @param r Kolor czerwony.
    * @param g Kolor zielony.
    * @param b Kolor niebieski.
    */
    Polyline(const std::vector<SDL_FPoint>& pts, Uint8 r, Uint8 g, Uint8 b);
    /**
    * @brief Przesuwa liniê ³aman¹.
    *
    * @param dx Przesuniêcie w pozycji X.
    * @param dy Przesuniêcie w pozycji Y.
    */
    void translate(float dx, float dy) override;
    /**
    * @brief Obraca liniê ³aman¹.
    *
    * @param angle K¹t obrotu.
    *
    */
    void rotate(float angle) override;
    /**
    * @brief Skaluje liniê ³aman¹.
    *
    * @param sx Skala w pozycji X.
    * @param sy Skala w pozycji Y.
    */
    void scale(float sx, float sy) override;
    /**
    * @brief Rysuje liniê ³aman¹.
    *
    * @param WskaŸnik na renderer u¿ywany do rysowania.
    */
    void draw(SDL_Renderer* renderer) override;
    void update(float dt) override;
    /**
    * @brief Sprawdza czy punkt znajduje siê na linii ³amanej.
    *
    * @param dx Pozycja X punktu.
    * @param dy Pozycja Y punktu.
    */
    bool containsPoint(float dx, float dy) override;
};