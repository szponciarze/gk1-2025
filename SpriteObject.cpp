
#include "SpriteObject.h"

SpriteObject::SpriteObject(float x, float y, float w, float h, float animSpeed)
// Wywo³ujemy konstruktor bazowy BitmapObject z pustym wektorem bitmap
    : BitmapObject(x, y, w, h, {}), m_animSpeed(animSpeed), m_animTimer(0.0f), m_currentAnimation("")
{
}

void SpriteObject::addAnimation(const std::string& name, const std::vector<std::string>& bitmapIDs)
{
    m_animations[name] = bitmapIDs;
}

void SpriteObject::setAnimation(const std::string& name)
{
    // Zmieñ animacjê tylko, jeœli jest inna od bie¿¹cej i istnieje w mapie
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
    // G³ówna metoda aktualizacji obiektu - wywo³uje logikê animacji
    animate(dt);
}

void SpriteObject::animate(float dt)
{
    // Jeœli nie mamy ¿adnych klatek w bie¿¹cej animacji, nic nie rób
    if (m_bitmapIDs.empty()) {
        return;
    }

    // Czas, po którym powinna nast¹piæ zmiana klatki
    float timePerFrame = 1.0f / m_animSpeed;

    m_animTimer += dt;

    // Jeœli up³ynê³o wystarczaj¹co du¿o czasu, przejdŸ do nastêpnej klatki
    if (m_animTimer >= timePerFrame)
    {
        m_animTimer -= timePerFrame;
        // U¿ywamy modulo, aby animacja zapêtla³a siê
        m_currentFrame = (m_currentFrame + 1) % m_bitmapIDs.size();
    }
}