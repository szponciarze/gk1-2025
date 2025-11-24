
#pragma once
#include "UpdatableObject.h"

// Dziedziczy po UpdatableObject, aby wpasowac sie w glowna petle silnika.
class AnimatedObject : public virtual UpdatableObject {
public:
    virtual ~AnimatedObject() = default;

    
    // Przekazujemy dt (delta time), aby animacja byla plynna i niezalezna od FPS.
    virtual void animate(float dt) = 0;
};