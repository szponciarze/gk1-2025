#pragma once
#include "SpriteObject.h" // Zmieniamy dziedziczenie

class Player : public SpriteObject {
private:
    float speed = 200.0f; // Predkosc w pikselach na sekunde

public:
    // Konstruktor przyjmuje tylko pozycje i wymiary, bez kolorow
    Player(float x, float y, float w, float h);

    // Nadpisujemy update, by dodac obs³uge klawiatury
    void update(float dt) override;


private:
    // Prywatna metoda do obs³ugi wejscia
    void handleKeyboard(const Uint8* keystates, float dt);
};