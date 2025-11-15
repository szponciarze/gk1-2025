#include "EllipseFilled.h"
#include <cmath>

EllipseFilled::EllipseFilled(float cx, float cy, float rx, float ry, Uint8 r, Uint8 g, Uint8 b)
    : cx(cx), cy(cy), rx(rx), ry(ry), r(r), g(g), b(b) {
}

void EllipseFilled::translate(float dx, float dy) {
    cx += dx;
    cy += dy;
}

void EllipseFilled::scale(float sx, float sy) {
    rx *= sx;
    ry *= sy;
}

void EllipseFilled::draw(SDL_Renderer* renderer) {
    if (!renderer) return;

    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    for (float alpha = 0; alpha < M_PI / 2; alpha += 0.01f) {
        int x = (int)(rx * cos(alpha));
        int y = (int)(ry * sin(alpha));

        for (int dx = -x; dx <= x; dx++) {
            SDL_RenderDrawPoint(renderer, cx + dx, cy + y);
            SDL_RenderDrawPoint(renderer, cx + dx, cy - y);
        }
    }
}

void EllipseFilled::update(float dt) {
    // ruch w gore i dol
    translate(0, sin(SDL_GetTicks() * 0.002f));
}