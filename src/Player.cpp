
#include "Player.h"

	Player::Player(shared_ptr<ofxFBX> model, shared_ptr<GameObject> gameObject, string name) :Component(gameObject, name) {
		
		this->animation = make_shared<Animation>(model, gameObject);
		this->animation->setAnimation(1);
		gameObject->addComponent(this->animation);
		
	}

	//--------------------------------------------------------------
	void Player::update() {

	}

	//--------------------------------------------------------------

	void Player::draw() {

	}
	//--------------------------------------------------------------