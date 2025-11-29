/**
* @file BitmapObject.h
* @brief Klasa objektu rysowanego za pomoc¹ bitmap.
* 
* BitmapObject reprezentuje obiekt graficzny, który wykorzystuje 
* bitmapy ³adowane przez BitmapHandler.
*/
#pragma once
#include "ShapeObject.h"
#include "UpdatableObject.h" 
#include <string>
#include <vector>

// Klasa bazowa dla obiektow rysowanych za pomoc¹ bitmap.
// Zmieniamy dziedziczenie, aby zawieralo UpdatableObject
/**
* @class BitmapObject
* @brief Obiekt rysowany za pomoc¹ bitmap.
* 
* Dziedziczy po ShapeObject oraz UpdatableObject.Co 
* umo¿liwia rotacjê, skalowanie itp. 
*/
class BitmapObject : public ShapeObject, public virtual UpdatableObject {
protected:
    /**
    * @brief Wektor zawieraj¹cy identyfikatory bitmap.
    */
    std::vector<std::string> m_bitmapIDs;
    /**
    * @brief Aktualnie wyœwietlana klatka.
    */
    int m_currentFrame;
   

public:
    /**
    * @brief Konstruktor BitmapObject
    * 
    * @param x Pozycja X obiektu.
    * @param y Pozycja Y obiektu.
    * @param w Szerokoœæ obiektu.
    * @param h Wysokoœæ obiektu.
    * @param bitmapIDs Wektor identyfikatoró bitmap.
    */
    BitmapObject(float x, float y, float w, float h, const std::vector<std::string>& bitmapIDs);
    /**
    * @brief Rysuje aktualn¹ bitmapê.
    * @param renderer WskaŸnik na renderer u¿ywany do rysowania.
    */
    void draw(SDL_Renderer* renderer) override;
   
    void update(float dt) override;
};