
#include "SpriteObject.h"

SpriteObject::SpriteObject(float x, float y, float w, float h, float animSpeed)
// Wywolujemy konstruktor bazowy BitmapObject z pustym wektorem bitmap
    : BitmapObject(x, y, w, h, {}), m_animSpeed(animSpeed), m_animTimer(0.0f), m_currentAnimation("")
{
}

void SpriteObject::addAnimation(const std::string& name, const std::vector<std::string>& bitmapIDs)
{
    m_animations[name] = bitmapIDs;
}

void SpriteObject::setAnimation(const std::string& name)
{
    // Zmien animacje tylko, jesli jest inna od biezacej i istnieje w mapie
    if (m_currentAnimation != name && m_animations.count(name))
    {
        m_currentAnimation = name;
        // Ustawiamy wektor ID bitmap w klasie bazowej (BitmapObject) na klatki nowej animacji
        m_bitmapIDs = m_animations[name];
        // Resetujemy animacjê
        m_currentFrame = 0;
        m_animTimer = 0.0f;
    }
}

void SpriteObject::update(float dt)
{
    // G³owna metoda aktualizacji obiektu - wywoluje logike animacji
    animate(dt);
}

void SpriteObject::animate(float dt)
{
    // Jesli nie mamy zadnych klatek w biez¹cej animacji, nic nie rbb
    if (m_bitmapIDs.empty()) {
        return;
    }

    // Czas, po którym powinna nastapic zmiana klatki
    float timePerFrame = 1.0f / m_animSpeed;

    m_animTimer += dt;

    // Jesli uplynê³o wystarczaj¹co duzo czasu, przejdz do nastepnej klatki
    if (m_animTimer >= timePerFrame)
    {
        m_animTimer -= timePerFrame;
        // Uzywamy modulo, aby animacja zapetlala sie
        m_currentFrame = (m_currentFrame + 1) % m_bitmapIDs.size();
    }

}