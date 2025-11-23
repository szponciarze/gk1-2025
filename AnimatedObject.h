
#pragma once

#include "UpdatableObject.h"

// Klasa bazowa dla wszystkich obiektów, które mo¿na animowaæ.
// Dziedziczy po UpdatableObject, aby wpasowaæ siê w g³ówn¹ pêtlê silnika.
class AnimatedObject : public virtual UpdatableObject {
public:
    virtual ~AnimatedObject() = default;

    // Czysto wirtualna metoda, któr¹ musz¹ zaimplementowaæ klasy pochodne.
    // Odpowiada za logikê zmiany klatek animacji.
    // Przekazujemy dt (delta time), aby animacja by³a p³ynna i niezale¿na od FPS.
    virtual void animate(float dt) = 0;
};