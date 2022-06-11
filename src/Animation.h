#pragma once

#include "Component.h"
#include "ofxFBX.h"
#include "GameObject.h"
#include "InputManager.h"

class Animation : public Component{
private:
	shared_ptr<ofxFBX> model;
	string state;

public:
	Animation(shared_ptr<ofxFBX> model, shared_ptr<GameObject> gameObject, string name="Animation Component");

	void setAnimation(string name);
	void setAnimation(int index);
	void addEventHandler(InputManager& inputManager,string name);

	void setState(string newState);
	string getState();

	void update();
	void draw();

};