// Plik: BitmapObject.cpp
#include "BitmapObject.h"
#include "Bitmap.h"
#include <iostream>

// Deklaracja, ¿e zmienna bitmapHandler istnieje gdzieœ indziej (w Engine.cpp)
// Pozwala nam to na dostêp do globalnego mened¿era bitmap.
extern BitmapHandler bitmapHandler;

BitmapObject::BitmapObject(float x, float y, float w, float h, const std::vector<std::string>& bitmapIDs)
    : m_x(x), m_y(y), m_w(w), m_h(h), m_bitmapIDs(bitmapIDs), m_currentFrame(0)
{
}

void BitmapObject::draw(SDL_Renderer* renderer)
{
    // Sprawdzamy, czy mamy jakiekolwiek bitmapy do narysowania
    if (m_bitmapIDs.empty() || m_currentFrame >= m_bitmapIDs.size()) {
        return;
    }

    // Pobieramy ID bie¿¹cej klatki i renderujemy j¹ za pomoc¹ BitmapHandler
    const std::string& currentBitmapID = m_bitmapIDs[m_currentFrame];
    bitmapHandler.renderBitmap(renderer, currentBitmapID, static_cast<int>(m_x), static_cast<int>(m_y), static_cast<int>(m_w), static_cast<int>(m_h));
}

void BitmapObject::translate(float dx, float dy)
{
    m_x += dx;
    m_y += dy;
}

void BitmapObject::rotate(float angle)
{
    // Nie implementujemy rotacji dla bitmap w tym zadaniu
}

void BitmapObject::scale(float sx, float sy)
{
    m_w *= sx;
    m_h *= sy;
}

void BitmapObject::update(float dt)
{
    // Pusta implementacja, sama bitmapa nie ma logiki aktualizacji
}