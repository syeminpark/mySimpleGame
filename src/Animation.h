#pragma once

#include "Component.h"
#include "ofxFBX.h"
#include "GameObject.h"


class Animation : public Component{
private:
	shared_ptr<ofxFBX> model;

public:
	Animation(shared_ptr<ofxFBX> model, shared_ptr<GameObject> gameObject, string name="Animation Component");

	void setAnimation(string name);
	void setAnimation(int index);
	void update();
	void draw();
};