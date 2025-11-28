#include "EllipseFilled.h"
#include <cmath>
#include <algorithm>
#include <iostream> 

EllipseFilled::EllipseFilled(float cx, float cy, float rx, float ry, Uint8 r, Uint8 g, Uint8 b)
    : ShapeObject(cx, cy, rx * 2, ry * 2), 
    cx(cx), cy(cy), rx(rx), ry(ry),
    rotation(0.0f),
    r(r), g(g), b(b) {

    
    m_x = cx;
    m_y = cy;
}

void EllipseFilled::translate(float dx, float dy) {
    m_x += dx;
    m_y += dy;
    cx += dx;
    cy += dy;
}

void EllipseFilled::rotate(float angle) {
    rotation += angle;
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

    
    float rad = rotation * M_PI / 180.0f;
    float cosA = cos(-rad);
    float sinA = sin(-rad);


    float maxR = std::max(rx, ry);
    int range = static_cast<int>(maxR + 2); 

    int minX = static_cast<int>(cx - range);
    int maxX = static_cast<int>(cx + range);
    int minY = static_cast<int>(cy - range);
    int maxY = static_cast<int>(cy + range);

  
    for (int py = minY; py <= maxY; py++) {
        for (int px = minX; px <= maxX; px++) {

            float dx = px - cx;
            float dy = py - cy;

          
            float localX = dx * cosA - dy * sinA;
            float localY = dx * sinA + dy * cosA;

           
            if (((localX * localX) / (rx * rx) + (localY * localY) / (ry * ry)) <= 1.0f) {
                SDL_RenderDrawPoint(renderer, px, py);
            }
        }
    }
}

void EllipseFilled::update(float dt) {
   
}

bool EllipseFilled::containsPoint(float px, float py) {
    float rad = rotation * M_PI / 180.0f;
    float cosA = cos(-rad);
    float sinA = sin(-rad);

    float dx = px - cx;
    float dy = py - cy;

    float localX = dx * cosA - dy * sinA;
    float localY = dx * sinA + dy * cosA;

    return ((localX * localX) / (rx * rx) + (localY * localY) / (ry * ry)) <= 1.0f;
}