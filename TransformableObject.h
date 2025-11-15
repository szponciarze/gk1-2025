#pragma once
#include "GameObject.h"

class TransformableObject : public virtual GameObject {
public:
	TransformableObject();
	virtual ~TransformableObject();
	virtual void translate(float tx, float ty);
	virtual void rotate(float angle);
	virtual void scale(float sx, float sy);
};