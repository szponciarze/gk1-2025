#pragma once
#include "SpriteObject.h" 

class Player : public SpriteObject {
private:
    float speed = 200.0f; 

public:
    // Konstruktor przyjmuje tylko pozycje i wymiary, bez kolorow
    Player(float x, float y, float w, float h);

    // Nadpisujemy update, by dodac obs³uge klawiatury
    void update(float dt) override;


private:
    void handleKeyboard(const Uint8* keystates, float dt);
};