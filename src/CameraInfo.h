#pragma once

#include "ofMain.h"
#include "Component.h"

class CameraInfo : public Component {
private:

public:
	CameraInfo(shared_ptr<GameObject> gameObject, string name= "CameraInfo Component");
	void update();
	void draw();
};