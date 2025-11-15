#pragma once
#include "ShapeObject.h"
#include "UpdatableObject.h"
#include <vector>

class Polyline : public ShapeObject, public UpdatableObject {
private:
    std::vector<SDL_FPoint> points;
    Uint8 r, g, b;

public:
    Polyline(const std::vector<SDL_FPoint>& pts, Uint8 r, Uint8 g, Uint8 b);

    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float sx, float sy) override;

    void draw(SDL_Renderer* renderer) override;
    void update(float dt) override;
};