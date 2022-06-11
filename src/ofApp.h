#pragma once

#include "ofMain.h"
#include "ofxGrabCam.h"
#include "ofxFBX.h"

#include "ModelImporter.h"
#include "Player.h"
#include "GameObjectManager.h"

#include "InputManager.h"
#include "CameraInfo.h"
#include "GlobalSetting.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key); 
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofxGrabCam camera;
		ofLight light;

		GlobalSetting globalSetting = { 4 };
		GameObjectManager gameObjectManager;
		InputManager inputManager;

};


