#include "Ellipse.h"
#include <cmath>

Ellipse::Ellipse(float cx, float cy, float rx, float ry, Uint8 r, Uint8 g, Uint8 b)
    : cx(cx), cy(cy), rx(rx), ry(ry), rotation(0), r(r), g(g), b(b) {
}

void Ellipse::translate(float dx, float dy) {
    cx += dx;
    cy += dy;
}

void Ellipse::rotate(float angle) {
    rotation += angle;
}

void Ellipse::scale(float sx, float sy) {
    rx *= sx;
    ry *= sy;
}

void Ellipse::draw(SDL_Renderer* renderer) {
    if (!renderer) return;

    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    float rad = rotation * M_PI / 180.0f;

    for (float alpha = 0; alpha <= 2 * M_PI; alpha += 0.01f) {
        float x = rx * cos(alpha);
        float y = ry * sin(alpha);

        
        float xr = cos(rad) * x - sin(rad) * y;
        float yr = sin(rad) * x + cos(rad) * y;

        SDL_RenderDrawPoint(renderer, (int)(cx + xr), (int)(cy + yr));
    }
}

void Ellipse::update(float dt) {
    // krecenie sie elipsy
    rotate(20.0f * dt);
}