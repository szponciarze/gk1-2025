#include "Rectangle.h"
#include <SDL.h>
#include <cmath>

Rectangle::Rectangle(float x, float y, float w, float h, Uint8 r, Uint8 g, Uint8 b) //konstruktor
    : x(x), y(y), width(w), height(h), rotation(0), r(r), g(g), b(b) {
}

void Rectangle::translate(float dx, float dy) { //przesuniecie prostokata
    x+=dx;
    y+=dy; 
}
void Rectangle::rotate(float angle) { //rotacja prostokata
    rotation+=angle; 
}
void Rectangle::scale(float sx, float sy) { //skalowanie prostokata
    width*=sx;
    height*=sy; 
}

void Rectangle::draw(SDL_Renderer* renderer) { //glowna metoda - rysowanie prostokata
    if (!renderer) return;

    //obliczanie srodka prostokata
    float cx = x+width/2.0f;
    float cy = y+height/2.0f;

    //wierzcholki prostokata przed obrotem
    float corners[4][2] = {
        {x,y},
        {x+width, y},
        {x+width, y+height},
        {x, y+height}
    };

    float rad = rotation*M_PI/180.0f; //konwersja stopni na radiany
    SDL_Point points[5];

    for (int i=0; i<4; ++i) {
        float px=corners[i][0];
        float py=corners[i][1];

        points[i].x=(int)(cx +(px - cx)*cos(rad)-(py - cy)*sin(rad));
        points[i].y=(int)(cy +(px - cx)*sin(rad)+(py - cy)*cos(rad));
    }
    points[4]=points[0]; // zamkniêcie prostok¹ta

    SDL_SetRenderDrawColor(renderer,r,g,b,255);
    SDL_RenderDrawLines(renderer,points,5);
    //rysoawnie prostokata na rendererze
}

void Rectangle::update(float dt) {
    //obrot prostokata
    Rectangle::rotate(100.0f*dt);
}