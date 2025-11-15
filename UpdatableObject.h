#pragma once
#include "GameObject.h"

class UpdatableObject : public virtual GameObject {
public:
	UpdatableObject();
	virtual ~UpdatableObject();
	virtual void update(float dt)=0;
};