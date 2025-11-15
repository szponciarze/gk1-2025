#pragma once
#include "ShapeObject.h"
#include "UpdatableObject.h"
#include <SDL.h>

class EllipseFilled : public ShapeObject, public UpdatableObject {
private:
    float cx, cy;
    float rx, ry;
    Uint8 r, g, b;

public:
    EllipseFilled(float cx, float cy, float rx, float ry, Uint8 r, Uint8 g, Uint8 b);

    void translate(float dx, float dy) override;
    void rotate(float angle) override {}
    void scale(float sx, float sy) override;

    void draw(SDL_Renderer* renderer) override;
    void update(float dt) override;
};