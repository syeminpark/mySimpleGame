#pragma once

#include "Component.h"
#include "Animation.h"
#include "ofxFBX.h"
#include "GameObject.h"
#include "InputManager.h"
#include "GlobalSetting.h"


class Player : public Component {

private:
	shared_ptr<Animation> animation;
	shared_ptr<ofxFBX> model;

	function<void()> selectCallback(InputManager& inputManager, GlobalSetting& globalSetting, string name);

public:
	Player(shared_ptr<ofxFBX> model, shared_ptr<GameObject> gameObject, string name="Player Component");
	void update();
	void addEventHandler(InputManager &inputManager, GlobalSetting &globalSetting, string name);
	void draw();
};

