#pragma once
#include "ShapeObject.h"
#include "UpdatableObject.h"

class Line : public ShapeObject, public UpdatableObject {
private:
    float x1, y1;
    float x2, y2;
    float rotation;
    Uint8 r, g, b;

public:
    Line(float x1, float y1, float x2, float y2, Uint8 r, Uint8 g, Uint8 b);

    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float sx, float sy) override;

    void draw(SDL_Renderer* renderer) override;
    void update(float dt) override;
};