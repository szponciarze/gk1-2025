#include "CircleFilled.h"
#include <SDL.h>

CircleFilled::CircleFilled(float x, float y, float radius, Uint8 r, Uint8 g, Uint8 b)
    : ShapeObject(x, y, 0, 0), radius(radius), r(r), g(g), b(b) {
}

void CircleFilled::translate(float dx,float dy) {//przesuniecie kola
    m_x+=dx;
    m_y+=dy;
}

void CircleFilled::rotate(float angle) {
    //obrot kola nic nie wnosi
}

void CircleFilled::scale(float sx, float sy) {//skalowanie kola
    radius *= (sx+sy)/2.0f;
}

void CircleFilled::draw(SDL_Renderer* renderer) {//glowna metoda - rysowanie wypelnionego
    if (!renderer) return;
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            if (x * x + y * y <= radius * radius) {
                SDL_RenderDrawPoint(renderer, (int)(m_x+x), (int)(m_y+y));
            }
        }
    }
}

void CircleFilled::update(float dt) {
    //przesuwanie kola w dol
    //translate(0,50.0f*dt);
}

bool CircleFilled::containsPoint(float px, float py) {
    float dx = px - m_x;
    float dy = py - m_y;
    return dx * dx + dy * dy <= radius * radius;
}