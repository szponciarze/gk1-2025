/**
* @file Bitmap.h
* @brief Klasa zarz¹dzaj¹ca wczytywaniem, przechowywaniem oraz renderowaniem bitmap.
*/
#pragma once
#include <SDL.h>
#include <string>
#include <unordered_map>

/**
* @class BitmapHandler
* @brief Obs³uga bitmap.
* 
* Klasa umo¿liwia wczytywanie bitmap jako tekstur,
* usuwanie ich oraz renderowanie. Przechowuje tekstury w s³owniku
* unirdered_map.
*/
class BitmapHandler {
public:
    /**
    * @brief Domyœlny konstruktor BitmapHandler.
    */
    BitmapHandler()= default;
    /**
    * @brief Destruktor zwalniaj¹cy tekstury.
    */
    ~BitmapHandler();
    /**
    * @brief Wczytuje bitmapê i tworzy teksturê.
    * @param renderer WskaŸnik na renderer u¿ywany do tworzenia tekstury.
    * @param id Unikalny identyfikator tekstury.
    * @param filePath Œcie¿ka do bitmapy.
    * @return true Jeœli uda³o siê utworzyæ teksturê, false w przeciwnym wypadku.
    */
    bool loadBitmap(SDL_Renderer* renderer, const std::string& id, const std::string& filePath);

    /**
    * @brief Usuwa teksture o podanym id.
    * @param id Unikalny identyfikatir tekstury.
    */
    void removeBitmap(const std::string& id);

    /**
    * @brief Renderuje wybran¹ bitmapê w podanej pozycji.
    * @param renderer WskaŸnik na renderer u¿ywany do rysowania tekstury.
    * @param id Unikalny identyfikator tekstury.
    * @param x Pozycja X na ekranie.
    * @param y Pozycja Y na ekranie.
    * @param w Szerokoœæ, jeœli nie podana u¿ywana jest szerokoœæ domyœlna.
    * @param h Wysokoœæ, jeœli nie podana u¿ywana jest wysokoœæ domyœlna.
    */
    void renderBitmap(SDL_Renderer* renderer, const std::string& id, int x, int y, int w = 0, int h = 0);

private:
    /**
    * @brief S³ownik tekstur.
    * 
    * Klucz: Unikalny identyfikator tekstury.
    * Wartoœæ: WskaŸnik na SDL_Texture.
    */
    std::unordered_map<std::string, SDL_Texture*> m_textures;
};
