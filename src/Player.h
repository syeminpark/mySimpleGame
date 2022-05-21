#pragma once

#include "Component.h"
#include "Animation.h"
#include "ofxFBX.h"
#include "GameObject.h"


class Player : public Component {

private:
	shared_ptr<Animation> animation;

public:
	Player(shared_ptr<ofxFBX> model, shared_ptr<GameObject> gameObject, string name="Player Component");
	void update();
	void draw();
};