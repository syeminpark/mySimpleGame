#pragma once

#include "GameObject.h"
#include "SafeArray.h"


class GameObjectManager {

private:
	SafeArray<shared_ptr<GameObject>>gameObjects;

public:
	shared_ptr<GameObject> createGameObject(string name);
	void removeGameObject(shared_ptr<GameObject> gameObject);
	void update();
	void draw();
};