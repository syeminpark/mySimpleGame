#pragma once

#include "ofMain.h"

class GameObject;
//base class 
class Component {
protected:
	shared_ptr<GameObject> gameObject;
	string name;

public:
	Component(shared_ptr<GameObject> gameObject, string name="Component");
	virtual void update() = 0;
	virtual void draw() = 0;
	string getName() const;
};  