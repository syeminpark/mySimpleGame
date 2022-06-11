
#include "Player.h"

	Player::Player(shared_ptr<ofxFBX> model, shared_ptr<GameObject> gameObject, string name) :Component(gameObject, name) {
		
		this->model = model;
		this->animation = make_shared<Animation>(model, gameObject);
		this->animation->setAnimation(1);
		gameObject->addComponent(this->animation);
		
	}

	//--------------------------------------------------------------
	void Player::update() {
		// the alternative to the callbacks system would be.. 
		//if (inputManager.isPressed(name)) execute function;
	}

	void Player::addEventHandler(InputManager& inputManager, GlobalSetting& globalSetting, string name) {
		inputManager.assignCallback(name, selectCallback(inputManager, globalSetting, name));
	}

	function<void()> Player::selectCallback(InputManager& inputManager, GlobalSetting &globalSetting, string name) {

		if (name == "left") {
			return [globalSetting, this]() {
				float rotation = this->model->getHeadingDeg();
				if (this->model->getPitchDeg() >= 0)rotation += 1 * globalSetting.speed;
				else if (this->model->getPitchDeg() < 0)rotation -= 1 * globalSetting.speed;;
				this->model->setOrientation({ this->model->getPitchDeg(),rotation,this->model->getRollDeg() });
			};
		}

		else if (name == "right") {
			return [globalSetting, this]() {
				float rotation = this->model->getHeadingDeg();
				if (this->model->getPitchDeg() >= 0)rotation -= 1 * globalSetting.speed;
				else if (this->model->getPitchDeg() < 0)rotation += 1 * globalSetting.speed;
				this->model->setOrientation({ this->model->getPitchDeg(),rotation,this->model->getRollDeg() });
			};
		}

		else if (name == "front") {
			return [globalSetting, this]() {
				glm::vec3 position = this->model->getPosition();
				position = position -= this->model->getLookAtDir() * globalSetting.speed;
				this->model->setPosition(position);
			};
		}

		else if (name == "back") {
			return [globalSetting, this]() {
				glm::vec3 position = this->model->getPosition();
				position = position += this->model->getLookAtDir() * globalSetting.speed;
				this->model->setPosition(position);
			};
		}
	}

	//--------------------------------------------------------------

	void Player::draw() {

	}
	//--------------------------------------------------------------

