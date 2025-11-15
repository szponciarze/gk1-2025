#pragma once
#include"DrawableObject.h"
#include"TransformableObject.h"

class ShapeObject : public DrawableObject, public TransformableObject {
public:
	ShapeObject();
	virtual ~ShapeObject();
	virtual void draw(SDL_Renderer* renderer);
	virtual void translate(float tx, float ty);
	virtual void rotate(float angle);
	virtual void scale(float sx, float sy);



};