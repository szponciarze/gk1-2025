/**
* @file Circle.h
* @brief Klasa reprezentuj¹ca okr¹g.
* 
* Circle dziedziczy po ShapeObject oraz UpdatableObject co umo¿liwia
* rotowanie, skalowanie itp. Zawiera kolor, promieñ i umo¿wliwa rysowanie.
*/
#pragma once
#include "ShapeObject.h"
#include "UpdatableObject.h"
#include <SDL.h>
/**
* @class Circle
* @brief Klasa reprezêtuj¹ca okr¹g.
* 
*/
class Circle:public ShapeObject, public UpdatableObject {
private:
    /**
    * @brief Promieñ okrêgu.
    */
    float radius;
    /**
    * @brief Kolor okrêgu.
    */
    Uint8 r,g,b;

public:
    /**
    * @brief Konstruktor okrêgu.
    * 
    * @param cx Pozycja X œrodka.
    * @param cy Pozycja Y œrodka.
    * @param radius Promieñ okrêgu.
    * @param r Kolor czerwony.
    * @param g Kolor zielony.
    * @param b Kolor niebieski.
    */
    Circle(float cx,float cy,float radius,Uint8 r,Uint8 g,Uint8 b);
    /**
    * @brief Przesuwa okr¹g.
    * 
    * @param dx Przesuniêcie w pozycji X.
    * @param dy Przesuniêcie w pozycji Y.
    */
    void translate(float dx,float dy) override;
    /**
    * @brief Obraca okr¹g.
    * 
    * @param angle K¹t obrotu.
    * 
    * Nie wykonuje ¿adnej operacji poniewa¿ okr¹g wygl¹da tak samo pod ka¿dym k¹tem.
    */
    void rotate(float angle) override;
    /**
    * @brief Skaluje okr¹g.
    * 
    * @param sx Skala w pozycji X.
    * @param sy Skala w pozycji Y.
    */
    void scale(float sx,float sy) override;
    /**
    * @brief Rysuje okr¹g.
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