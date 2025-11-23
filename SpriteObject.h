#pragma once

#include "BitmapObject.h"
#include "AnimatedObject.h"
#include <map>

// Klasa dla animowanych obiektów (sprite'ów).
// £¹czy mo¿liwoœæ rysowania bitmap (BitmapObject) z logik¹ animacji (AnimatedObject).
class SpriteObject : public BitmapObject, public AnimatedObject {
protected:
    // Mapa przechowuj¹ca nazwy animacji i odpowiadaj¹ce im sekwencje ID bitmap
    std::map<std::string, std::vector<std::string>> m_animations;
    std::string m_currentAnimation;

    float m_animSpeed; // Prêdkoœæ animacji w klatkach na sekundê
    float m_animTimer; // Wewnêtrzny licznik czasu do zmiany klatek

public:
    // Konstruktor przyjmuje tylko pozycjê i wymiary. Bitmapy dodaje siê póŸniej.
    SpriteObject(float x, float y, float w, float h, float animSpeed = 10.0f);

    // Dodaje now¹ sekwencjê animacji
    void addAnimation(const std::string& name, const std::vector<std::string>& bitmapIDs);

    // Ustawia bie¿¹c¹ animacjê do odtwarzania
    void setAnimation(const std::string& name);

    // Nadpisane metody wirtualne
    void update(float dt) override;
    void animate(float dt) override;
};
