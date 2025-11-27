#include "RectangleFilled.h"
#include <SDL.h>
#include <cmath>

RectangleFilled::RectangleFilled(float x, float y, float w, float h, Uint8 r, Uint8 g, Uint8 b)//konstruktor
    : x(x), y(y), width(w), height(h), rotation(0), r(r), g(g), b(b) {
    m_x = x;
    m_y = y;
}

void RectangleFilled::translate(float dx, float dy) { ///przesuniecie prostokata
    x+=dx;
    y+=dy;
}
void RectangleFilled::rotate(float angle) {//rotacja prostokata - nie dziala
    rotation+=angle;
}
void RectangleFilled::scale(float sx, float sy) {//skalowanie prostokata
    width*=sx;
    height*=sy;
}

void RectangleFilled::draw(SDL_Renderer* renderer) {//glowna metoda - rysowanie wypelnionego prostokata
    if (!renderer) return;

    SDL_SetRenderDrawColor(renderer,r,g,b,255);
    SDL_Rect rect = { static_cast<int>(x - width / 2.0f), static_cast<int>(y - height / 2.0f),
                      static_cast<int>(width), static_cast<int>(height) };
    SDL_RenderFillRect(renderer, &rect);
}

void RectangleFilled::update(float dt) {
    //przesuwanie prostokata w prawo
    //RectangleFilled::translate(100.0f*dt, 0);
}

bool RectangleFilled::containsPoint(float px, float py) {
    float dx = px - m_x;
    float dy = py - m_y;
    return (dx >= -width / 2.0f) && (dx <= width / 2.0f) &&
        (dy >= -height / 2.0f) && (dy <= height / 2.0f);
}