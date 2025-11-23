#include "Player.h"
#include <cmath> // Dla sqrt

Player::Player(float x, float y, float w, float h)
// Wywo³ujemy konstruktor bazowy SpriteObject, ustawiamy prêdkoœæ animacji na 8 klatek/s
    : SpriteObject(x, y, w, h, 8.0f)
{
    // Definiujemy wszystkie animacje zgodnie z zadaniem (Rysunek 3)
    // Zak³adamy, ¿e ID bitmap zosta³y wczytane w Engine
    addAnimation("walk_down", { "hero_down_0", "hero_down_1", "hero_down_2", "hero_down_3" });
    addAnimation("walk_up", { "hero_up_0", "hero_up_1", "hero_up_2", "hero_up_3" });
    addAnimation("walk_left", { "hero_left_0", "hero_left_1", "hero_left_2", "hero_left_3" });
    addAnimation("walk_right", { "hero_right_0", "hero_right_1", "hero_right_2", "hero_right_3" });

    // Definiujemy animacje "idle" (bezczynnoœci), u¿ywaj¹c tylko pierwszej klatki
    addAnimation("idle_down", { "hero_down_0" });
    addAnimation("idle_up", { "hero_up_0" });
    addAnimation("idle_left", { "hero_left_0" });
    addAnimation("idle_right", { "hero_right_0" });

    // Ustawiamy animacjê pocz¹tkow¹
    setAnimation("idle_down");
}

void Player::update(float dt)
{
    const Uint8* keystates = SDL_GetKeyboardState(nullptr);
    handleKeyboard(keystates, dt);

    // Wywo³ujemy update z klasy bazowej (SpriteObject), aby animacja dzia³a³a
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

    // Ustawianie odpowiedniej animacji na podstawie kierunku ruchu
    if (dx > 0) setAnimation("walk_right");
    else if (dx < 0) setAnimation("walk_left");
    else if (dy > 0) setAnimation("walk_down");
    else if (dy < 0) setAnimation("walk_up");
    else {
        // Jeœli gracz siê nie porusza, ustaw animacjê idle
        // Wybieramy idle na podstawie ostatniej animacji chodzenia
        if (m_currentAnimation == "walk_down") setAnimation("idle_down");
        else if (m_currentAnimation == "walk_up") setAnimation("idle_up");
        else if (m_currentAnimation == "walk_left") setAnimation("idle_left");
        else if (m_currentAnimation == "walk_right") setAnimation("idle_right");
    }

    // Normalizacja wektora ruchu, aby ruch po skosie nie by³ szybszy
    if (dx != 0.0f || dy != 0.0f) {
        float length = sqrt(dx * dx + dy * dy);
        dx /= length;
        dy /= length;
    }

    // Przesuniêcie gracza z uwzglêdnieniem delta time dla p³ynnego ruchu
    translate(dx * speed * dt, dy * speed * dt);
}