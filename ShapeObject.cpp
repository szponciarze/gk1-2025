#include"ShapeObject.h"

ShapeObject::ShapeObject(float x, float y, float w, float h)
:m_x(x), m_y(y), m_w(w), m_h(h){}
ShapeObject::~ShapeObject() {}

void ShapeObject::draw(SDL_Renderer* renderer) {}
void ShapeObject::translate(float tx, float ty) {
	m_x += tx;
	m_y += ty;
}
void ShapeObject::rotate(float angle) {}
void ShapeObject::scale(float sx, float sy) {
	m_w *= sx;
	m_h *= sy;
}

bool ShapeObject::containsPoint(float px, float py) {
		return (px >= m_x && px <= m_x + m_w && py >= m_y && py <= m_y + m_h);
}

float ShapeObject::getX() const { return m_x; }
float ShapeObject::getY() const { return m_y; }
