#include "Line.h"
#include "PrimitiveRenderer.h"
#include <cmath>

Line::Line(float x1, float y1, float x2, float y2, Uint8 r, Uint8 g, Uint8 b)
    : x1(x1), y1(y1), x2(x2), y2(y2), rotation(0), r(r), g(g), b(b) {
}

void Line::translate(float dx, float dy) {
    x1 += dx;
    y1 += dy;
    x2 += dx;
    y2 += dy;
}

void Line::rotate(float angle) {
    rotation += angle;

    //srodek odcinka
    float cx = (x1 + x2) / 2.0f;
    float cy = (y1 + y2) / 2.0f;

    float rad = rotation * M_PI / 180.0f;

    //punkt 1
    float px = x1, py = y1;
    x1 = cx + (px - cx) * cos(rad) - (py - cy) * sin(rad);
    y1 = cy + (px - cx) * sin(rad) + (py - cy) * cos(rad);

    //punkt 2
    px = x2; py = y2;
    x2 = cx + (px - cx) * cos(rad) - (py - cy) * sin(rad);
    y2 = cy + (px - cx) * sin(rad) + (py - cy) * cos(rad);
}

void Line::scale(float sx, float sy) {
    float cx = (x1 + x2) / 2.0f;
    float cy = (y1 + y2) / 2.0f;

    x1 = cx + (x1 - cx) * sx;
    y1 = cy + (y1 - cy) * sy;

    x2 = cx + (x2 - cx) * sx;
    y2 = cy + (y2 - cy) * sy;
}

void Line::draw(SDL_Renderer* renderer) {
    if (!renderer) return;

    PrimitiveRenderer rnd(renderer);
    rnd.incrementalAlgorithm(
        (int)x1, (int)y1,
        (int)x2, (int)y2,
        r, g, b
    );
}

void Line::update(float dt) {
    //przesuwanie w dol
    //translate(0, 50.0f * dt);
}

bool Line::containsPoint(float px, float py) {
    
    float dx = x2 - x1;
    float dy = y2 - y1;
    float length2 = dx * dx + dy * dy;
    if (length2 == 0) return false; 
    float t = ((px - x1) * dx + (py - y1) * dy) / length2;
    t = std::fmax(0, std::fmin(1, t));
    float closestX = x1 + t * dx;
    float closestY = y1 + t * dy;
    float dist2 = (px - closestX) * (px - closestX) + (py - closestY) * (py - closestY);
    return dist2 <= 5.0f * 5.0f; // tolerancja 5px
}