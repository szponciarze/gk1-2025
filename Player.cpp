#include "Player.h"
#include <cmath> 

Player::Player(float x, float y, float w, float h)
// Wywolujemy konstruktor bazowy SpriteObject, ustawiamy prêdkosc animacji na 8 klatek/s
    : SpriteObject(x, y, w, h, 8.0f)
{

    addAnimation("walk_down", { "hero_down_0", "hero_down_1", "hero_down_2", "hero_down_3" });
    addAnimation("walk_up", { "hero_up_0", "hero_up_1", "hero_up_2", "hero_up_3" });
    addAnimation("walk_left", { "hero_left_0", "hero_left_1", "hero_left_2", "hero_left_3" });
    addAnimation("walk_right", { "hero_right_0", "hero_right_1", "hero_right_2", "hero_right_3" });

    // Definiujemy animacje "idle" (bezczynnosci), uzywaj¹c tylko pierwszej klatki
    addAnimation("idle_down", { "hero_down_0" });
    addAnimation("idle_up", { "hero_up_0" });
    addAnimation("idle_left", { "hero_left_0" });
    addAnimation("idle_right", { "hero_right_0" });

    // Ustawiamy animacje poczatkowa
    setAnimation("idle_down");
}

void Player::update(float dt)
{
    const Uint8* keystates = SDL_GetKeyboardState(nullptr);
    handleKeyboard(keystates, dt);

 
    SpriteObject::update(dt);
}

void Player::handleKeyboard(const Uint8* keystates, float dt)
{
    float dx = 0.0f;
    float dy = 0.0f;

    if (keystates[SDL_SCANCODE_W]) dy -= 1.0f;
    if (keystates[SDL_SCANCODE_S]) dy += 1.0f;
    if (keystates[SDL_SCANCODE_A]) dx -= 1.0f;
    if (keystates[SDL_SCANCODE_D]) dx += 1.0f;

    
    if (dx > 0) setAnimation("walk_right");
    else if (dx < 0) setAnimation("walk_left");
    else if (dy > 0) setAnimation("walk_down");
    else if (dy < 0) setAnimation("walk_up");
    else {
    
        // Wybieramy idle na podstawie ostatniej animacji chodzenia
        if (m_currentAnimation == "walk_down") setAnimation("idle_down");
        else if (m_currentAnimation == "walk_up") setAnimation("idle_up");
        else if (m_currentAnimation == "walk_left") setAnimation("idle_left");
        else if (m_currentAnimation == "walk_right") setAnimation("idle_right");
    }

    // Normalizacja wektora ruchu, aby ruch po skosie nie byl szybszy
    if (dx != 0.0f || dy != 0.0f) {
        float length = sqrt(dx * dx + dy * dy);
        dx /= length;
        dy /= length;
    }

    // Przesuniecie gracza z uwzglednieniem delta time dla plynnego ruchu
    translate(dx * speed * dt, dy * speed * dt);
}