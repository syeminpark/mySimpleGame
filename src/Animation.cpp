
#include "Animation.h"

	Animation::Animation(shared_ptr<ofxFBX> model, shared_ptr<GameObject> gameObject, string name) :Component(gameObject, name) {
		this->model = model;
	}

	//--------------------------------------------------------------
	void Animation::setAnimation(string name) {
		this->model->setAnimation(name);
	}

	//--------------------------------------------------------------
	void Animation::setAnimation(int index) {
		this->model->setAnimation(index);
	}

	//--------------------------------------------------------------
	void Animation::update() {
		this->model->update();
	}

	//--------------------------------------------------------------
	void Animation::draw() {
		this->model->draw();
	}
	//--------------------------------------------------------------