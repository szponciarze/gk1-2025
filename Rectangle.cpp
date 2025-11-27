#include "Rectangle.h"
#include <SDL.h>
#include <cmath>

Rectangle::Rectangle(float x, float y, float w, float h, Uint8 r, Uint8 g, Uint8 b) //konstruktor
    : ShapeObject(x, y, w, h), r(r), g(g), b(b), rotation(0) {
}

void Rectangle::translate(float dx, float dy) { //przesuniecie prostokata
    m_x+=dx;
    m_y+=dy; 
}
void Rectangle::rotate(float angle) { //rotacja prostokata
    rotation += angle; // w stopniach
}
void Rectangle::scale(float sx, float sy) { //skalowanie prostokata
    m_w*=sx;
    m_h*=sy; 
}

void Rectangle::draw(SDL_Renderer* renderer) {
    if (!renderer) return;

    float cx = m_x + m_w / 2.0f;
    float cy = m_y + m_h / 2.0f;

    float corners[4][2] = {
        {m_x, m_y},
        {m_x + m_w, m_y},
        {m_x + m_w, m_y + m_h},
        {m_x, m_y + m_h}
    };

    float rad = rotation * M_PI / 180.0f;
    SDL_Point points[5];

    for (int i = 0; i < 4; i++) {
        float dx = corners[i][0] - cx;
        float dy = corners[i][1] - cy;
        points[i].x = (int)(cx + dx * cos(rad) - dy * sin(rad));
        points[i].y = (int)(cy + dx * sin(rad) + dy * cos(rad));
    }
    points[4] = points[0];

    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderDrawLines(renderer, points, 5);
}

void Rectangle::update(float dt) {
    //obrot prostokata
    //Rectangle::rotate(100.0f*dt);
}
