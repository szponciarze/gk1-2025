#include <SDL.h>
#include <string>
#include <unordered_map>

class BitmapHandler {
public:
    BitmapHandler()= default;
    ~BitmapHandler();

    bool loadBitmap(SDL_Renderer* renderer, const std::string& id, const std::string& filePath);


    void removeBitmap(const std::string& id);

   
    void renderBitmap(SDL_Renderer* renderer, const std::string& id, int x, int y, int w = 0, int h = 0);

private:
    std::unordered_map<std::string, SDL_Texture*> m_textures;
};
