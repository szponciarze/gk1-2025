#include "CircleFilled.h"
#include <SDL.h>

CircleFilled::CircleFilled(float cx, float cy, float radius, Uint8 r, Uint8 g, Uint8 b)//konstruktor
    : cx(cx), cy(cy), radius(radius), r(r), g(g), b(b) {
}

void CircleFilled::translate(float dx,float dy) {//przesuniecie kola
    cx+=dx;
    cy+=dy;
}

void CircleFilled::rotate(float angle) {
    //obrot kola nic nie wnosi
}

void CircleFilled::scale(float sx, float sy) {//skalowanie kola
    radius *= (sx+sy)/2.0f;
}

void CircleFilled::draw(SDL_Renderer* renderer) {//glowna metoda - rysowanie wypelnionego
    if (!renderer) return;

    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            if (x * x + y * y <= radius * radius) {
                SDL_SetRenderDrawColor(renderer,r,g,b,255);
                SDL_RenderDrawPoint(renderer, (int)(cx+x), (int)(cy+y));
            }
        }
    }
}

void CircleFilled::update(float dt) {
    //przesuwanie kola w dol
    translate(0,50.0f*dt);
}