#include"GameObject.h"
GameObject::GameObject() {
	id = nextId++;
}
GameObject::~GameObject() {}
int GameObject::nextId = 1; 
int GameObject::getId() const { return id; }