#pragma once
#include"DrawableObject.h"
#include"TransformableObject.h"

class ShapeObject : public DrawableObject, public TransformableObject {
protected:
	float m_x, m_y;
	float m_w, m_h;

public:
	ShapeObject(float x=0, float y=0, float w=0, float h =0);
	virtual ~ShapeObject();
	virtual void draw(SDL_Renderer* renderer);
	virtual void translate(float tx, float ty);
	virtual void rotate(float angle);
	virtual void scale(float sx, float sy);



};