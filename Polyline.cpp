#include "Polyline.h"
#include <cmath>

Polyline::Polyline(const std::vector<SDL_FPoint>& pts, Uint8 r, Uint8 g, Uint8 b)
    : points(pts), r(r), g(g), b(b) {
}

void Polyline::translate(float dx, float dy) {
    for (auto& p : points) {
        p.x += dx;
        p.y += dy;
    }
}

void Polyline::rotate(float angle) {
    float rad = angle * M_PI / 180.0f;
    float cx = points[0].x;

    for (auto& p : points) {
        float x = p.x - cx;
        float y = p.y - cx;

        p.x = cx + x * cos(rad) - y * sin(rad);
        p.y = cx + x * sin(rad) + y * cos(rad);
    }
}

void Polyline::scale(float sx, float sy) {
    float cx = points[0].x;
    float cy = points[0].y;

    for (auto& p : points) {
        p.x = cx + (p.x - cx) * sx;
        p.y = cy + (p.y - cy) * sy;
    }
}

void Polyline::draw(SDL_Renderer* renderer) {
    if (!renderer) return;

    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    for (size_t i = 0; i < points.size() - 1; i++) {
        SDL_RenderDrawLineF(renderer,
            points[i].x, points[i].y,
            points[i + 1].x, points[i + 1].y);
    }
}

void Polyline::update(float dt) {
    translate(20.0f * dt, 0);
}