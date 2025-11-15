#pragma once
#include "GameObject.h"
#include <SDL.H>

class DrawableObject : public virtual GameObject {
protected:
	//bool visible=true;
public:
	DrawableObject();
	virtual ~DrawableObject();

	virtual void draw(SDL_Renderer* renderer);

	//void setVisible(bool v) {
	//	visible=v;
	//}

	//bool isVisible() {
	//	return visible;
	//}



};