#include "RectangleFilled.h"
#include <SDL.h>
#include <cmath>
#include <algorithm>

RectangleFilled::RectangleFilled(float x, float y, float w, float h, Uint8 r, Uint8 g, Uint8 b)
    : ShapeObject(x, y, w, h), x(x), y(y), width(w), height(h), rotation(0), r(r), g(g), b(b) {
  
    m_x = x;
    m_y = y;
}

void RectangleFilled::translate(float dx, float dy) {

    x += dx;
    y += dy;
    m_x = x;
    m_y = y;
}

void RectangleFilled::rotate(float angle) {
    rotation += angle;
}

void RectangleFilled::scale(float sx, float sy) {
    width *= sx;
    height *= sy;
    m_w = width;
    m_h = height;
}

void RectangleFilled::draw(SDL_Renderer* renderer) {
    if (!renderer) return;

    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

 
    if (abs(rotation) < 0.1f) {
        SDL_Rect rect = {
            static_cast<int>(x - width / 2.0f),
            static_cast<int>(y - height / 2.0f),
            static_cast<int>(width),
            static_cast<int>(height)
        };
        SDL_RenderFillRect(renderer, &rect);
        return;
    }

    // --- RYSOWANIE OBROCONEGO (Piksel po pikselu) ---

    
    float rad = rotation * M_PI / 180.0f;
    float cosA = cos(-rad);
    float sinA = sin(-rad);
    float radius = sqrt(pow(width / 2.0f, 2) + pow(height / 2.0f, 2));

    int minX = static_cast<int>(x - radius);
    int maxX = static_cast<int>(x + radius);
    int minY = static_cast<int>(y - radius);
    int maxY = static_cast<int>(y + radius);

    for (int py = minY; py <= maxY; py++) {
        for (int px = minX; px <= maxX; px++) {

           
            float dx = px - x;
            float dy = py - y;

       
            float localX = dx * cosA - dy * sinA;
            float localY = dx * sinA + dy * cosA;

           
            if (fabs(localX) <= width / 2.0f && fabs(localY) <= height / 2.0f) {
                SDL_RenderDrawPoint(renderer, px, py);
            }
        }
    }
}

void RectangleFilled::update(float dt) {
   
}

bool RectangleFilled::containsPoint(float px, float py) {

    float rad = rotation * M_PI / 180.0f;
    float cosA = cos(-rad);
    float sinA = sin(-rad);

    float dx = px - x;
    float dy = py - y;

    float localX = dx * cosA - dy * sinA;
    float localY = dx * sinA + dy * cosA;

    return (fabs(localX) <= width / 2.0f && fabs(localY) <= height / 2.0f);
}