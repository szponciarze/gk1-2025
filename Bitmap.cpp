#include "Bitmap.h"
#include <iostream>

BitmapHandler::~BitmapHandler() {
    for (auto& pair : m_textures) {
        SDL_DestroyTexture(pair.second);
    }
    m_textures.clear();
}

bool BitmapHandler::loadBitmap(SDL_Renderer* renderer, const std::string& id, const std::string& filePath) {
    SDL_Surface* surface = SDL_LoadBMP(filePath.c_str());
    if (!surface) {
        std::cerr << "Blad ladowania pliku BMP: " << SDL_GetError() << " dla pliku: " << filePath << std::endl;
        return false;
    }
    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 255, 255));
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture) return false;

    m_textures[id] = texture;
    return true;
}

void BitmapHandler::removeBitmap(const std::string& id) {
    auto it = m_textures.find(id);
    if (it != m_textures.end()) {
        SDL_DestroyTexture(it->second);
        m_textures.erase(it);
    }
}

void BitmapHandler::renderBitmap(SDL_Renderer* renderer, const std::string& id, int x, int y, int w, int h) {
    auto it = m_textures.find(id);
    if (it == m_textures.end()) return;

    SDL_Texture* texture = it->second;

    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;

    if (w == 0 || h == 0) {
        SDL_QueryTexture(texture, nullptr, nullptr, &destRect.w, &destRect.h);
    }
    else {
        destRect.w = w;
        destRect.h = h;
    }

    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
}
