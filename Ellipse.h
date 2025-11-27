#pragma once
#include "ShapeObject.h"
#include "UpdatableObject.h"
#include <SDL.h>

class Ellipse : public ShapeObject, public UpdatableObject {
private:
    float cx, cy; 
    float rx, ry; 
    float rotation;
    Uint8 r, g, b;

public:
    Ellipse(float cx, float cy, float rx, float ry, Uint8 r, Uint8 g, Uint8 b);

    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float sx, float sy) override;

    void draw(SDL_Renderer* renderer) override;
    void update(float dt) override;
    bool containsPoint(float dx, float dy) override;
};