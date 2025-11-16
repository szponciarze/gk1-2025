#pragma once
#include "Rectangle.h"

class Player : public Rectangle {
public:
    Player(float x, float y, float w, float h, Uint8 r, Uint8 g, Uint8 b);

    void update(float dt) override;
    void draw(SDL_Renderer* renderer) override;

    

private:
    float speed = 200.0f;
    void handleKeyboard(const Uint8* keystates);
};
