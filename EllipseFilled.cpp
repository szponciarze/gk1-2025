#include "EllipseFilled.h"
#include <cmath>

EllipseFilled::EllipseFilled(float cx, float cy, float rx, float ry, Uint8 r, Uint8 g, Uint8 b)
    : ShapeObject(cx, cy, rx * 2, ry * 2), rx(rx), ry(ry), r(r), g(g), b(b) {
}

void EllipseFilled::translate(float dx, float dy) {
 
    m_x += dx;
    m_y += dy;
    cx += dx;
    cy += dy;
}

void EllipseFilled::scale(float sx, float sy) {
    rx *= sx;
    ry *= sy;
    m_w = rx * 2;
    m_h = ry * 2;
}

void EllipseFilled::draw(SDL_Renderer* renderer) {
    if (!renderer) return;

    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    for (int y = -ry; y <= ry; y++) {
        float t = 1.0f - ((float)y * y) / (ry * ry);
        if (t < 0) continue;

        int x = (int)(rx * sqrt(t));

        SDL_RenderDrawLine(renderer,(int)(m_x - x), (int)(m_y + y),(int)(m_x + x), (int)(m_y + y));
    }
}

void EllipseFilled::update(float dt) {
    // ruch w gore i dol
    //translate(0, sin(SDL_GetTicks() * 0.002f));
}

bool EllipseFilled::containsPoint(float px, float py) {
    float dx = px - m_x;
    float dy = py - m_y;
    return (dx * dx) / (rx * rx) + (dy * dy) / (ry * ry) <= 1.0f;
}