
#include "BitmapObject.h"
#include "Bitmap.h"
#include <iostream>


extern BitmapHandler bitmapHandler;

BitmapObject::BitmapObject(float x, float y, float w, float h, const std::vector<std::string>& bitmapIDs)
	:ShapeObject(x, y, w, h), m_bitmapIDs(bitmapIDs), m_currentFrame(0)
{
}

void BitmapObject::draw(SDL_Renderer* renderer)
{
    if (m_bitmapIDs.empty() || m_currentFrame >= m_bitmapIDs.size()) {
        return;
    }

    const std::string& currentBitmapID = m_bitmapIDs[m_currentFrame];
    bitmapHandler.renderBitmap(renderer, currentBitmapID, static_cast<int>(m_x), static_cast<int>(m_y), static_cast<int>(m_w), static_cast<int>(m_h));
}


void BitmapObject::update(float dt)
{

}