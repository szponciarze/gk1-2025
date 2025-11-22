#include "Player.h"
#include <SDL.h>

Player::Player(float x, float y, float w, float h, Uint8 r, Uint8 g, Uint8 b)
    : Rectangle(x, y, w, h, r, g, b)
{
}

void Player::update(float dt)
{
    const Uint8* keystates = SDL_GetKeyboardState(nullptr);
    handleKeyboard(keystates);
 
}

void Player::draw(SDL_Renderer* renderer)
{
    Rectangle::draw(renderer);
    
}

void Player::handleKeyboard(const Uint8* keystates)
{
    float dx = 0.0f;
    float dy = 0.0f;

    if (keystates[SDL_SCANCODE_W]) dy -= 1.0f;
    if (keystates[SDL_SCANCODE_S]) dy += 1.0f;
    if (keystates[SDL_SCANCODE_A]) dx -= 1.0f;
    if (keystates[SDL_SCANCODE_D]) dx += 1.0f;


    if (dx != 0.0f || dy != 0.0f) {
        float length = sqrt(dx * dx + dy * dy);
        dx /= length;
        dy /= length;
    }


    translate(dx * speed * 0.016f, dy * speed * 0.016f);
    
}
