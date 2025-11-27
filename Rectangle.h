#pragma once
#include"ShapeObject.h"
#include"UpdatableObject.h"
#include<SDL.h>
class Rectangle : public ShapeObject, public UpdatableObject {
protected:
    float x, y, width, height;
    float rotation;
private:
    
    
    Uint8 r,g,b;
public:
    Rectangle(float x, float y, float w, float h, Uint8 r = 255, Uint8 g = 0, Uint8 b = 0);
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float sx, float sy) override;
    void draw(SDL_Renderer* renderer) override;
    void update(float dt) override;
};