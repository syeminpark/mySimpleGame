#pragma once
#include "ofMain.h"
#include"ofxFBX.h"
#include "InputManager.h"
				
class Moveable {
private: 
	int axis;
	int direction;

	const int X = 0;
	const int Z = 2;

public:
	static const int speed = 2;

	void translate(string name) {

		if (name == "left") {
			this->axis = X;
			this->direction = -1;
		}
		else if (name == "right") {
			this->axis = X;
			this->direction = 1;
		}
		else if (name == "front") {
			this->axis = Z;
			this->direction = 1;
		}
		else if (name == "back") {
			this->axis = Z;
			this->direction = -1;
		}
	}

	void addEventHandler(InputManager &inputManager, shared_ptr<ofxFBX>model, string name) {
		inputManager.assignCallback(name, [this->axis, this->direction, model]() {
			model->setPosition(0, 0, model->getPosition()[axis] + 2 * direction);
			cout << "moved!, current pos: " << model->getPosition() << endl;
			});
	} 
};