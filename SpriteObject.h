#pragma once

#include "BitmapObject.h"
#include "AnimatedObject.h"
#include <map>

// L¹czy mozliwosc rysowania bitmap (BitmapObject) z logika animacji (AnimatedObject).
class SpriteObject : public BitmapObject, public AnimatedObject {
protected:

    std::map<std::string, std::vector<std::string>> m_animations;
    std::string m_currentAnimation;

    float m_animSpeed; 
    float m_animTimer; 

public:
    // Konstruktor przyjmuje tylko pozycje i wymiary. Bitmapy dodaje siê pozniej.
    SpriteObject(float x, float y, float w, float h, float animSpeed = 10.0f);

   
    void addAnimation(const std::string& name, const std::vector<std::string>& bitmapIDs);
    void setAnimation(const std::string& name);
    void update(float dt) override;
    void animate(float dt) override;
};
