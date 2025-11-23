#include "ShapeObject.h"
#include "UpdatableObject.h" // Dodajemy ten include dla jasnoœci
#include <string>
#include <vector>

// Klasa bazowa dla obiektów rysowanych za pomoc¹ bitmap.
// Zmieniamy dziedziczenie, aby zawiera³o UpdatableObject
class BitmapObject : public ShapeObject, public virtual UpdatableObject {
protected:
    std::vector<std::string> m_bitmapIDs;
    int m_currentFrame;
    float m_x, m_y, m_w, m_h;

public:
    BitmapObject(float x, float y, float w, float h, const std::vector<std::string>& bitmapIDs);

    void draw(SDL_Renderer* renderer) override;
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float sx, float sy) override;
    void update(float dt) override;
};