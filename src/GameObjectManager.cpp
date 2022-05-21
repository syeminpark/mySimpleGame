
#include "GameObjectManager.h"


	shared_ptr<GameObject> GameObjectManager::createGameObject() {
		shared_ptr<GameObject> gameObject = make_shared<GameObject>();
		this->gameObjects.add(gameObject);
		return gameObject;
	}

	//--------------------------------------------------------------
	void GameObjectManager::removeGameObject(shared_ptr<GameObject> gameObject) {
		this->gameObjects.remove(gameObject);
	}

	//--------------------------------------------------------------
	void GameObjectManager::update() {
		this->gameObjects.forEach([](shared_ptr<GameObject> element) {element->update();
		});
	}

	//--------------------------------------------------------------
	void GameObjectManager::draw() {
		this->gameObjects.forEach([](shared_ptr<GameObject> element) {element->draw(); 
});

	}

	//--------------------------------------------------------------