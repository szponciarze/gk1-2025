#include "ShapeObject.h"
#include "UpdatableObject.h" 
#include <string>
#include <vector>

// Klasa bazowa dla obiektow rysowanych za pomoc¹ bitmap.
// Zmieniamy dziedziczenie, aby zawieralo UpdatableObject
class BitmapObject : public ShapeObject, public virtual UpdatableObject {
protected:
    std::vector<std::string> m_bitmapIDs;
    int m_currentFrame;
   

public:
    BitmapObject(float x, float y, float w, float h, const std::vector<std::string>& bitmapIDs);

    void draw(SDL_Renderer* renderer) override;
   
    void update(float dt) override;
};