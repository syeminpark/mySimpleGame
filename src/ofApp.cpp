#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofDisableArbTex(); //default OF uses rectangular textures instead of 2D textures. legacy way. 

	ofSetFrameRate(30); //set frame rate 
	light.setPosition(-300, 300, -300);
	light.setAreaLight(100, 100);


	
		ModelImporter modelImporter;
		modelImporter.import({ "aj.fbx","kaya.fbx","ty.fbx" ,"vegas.fbx" });

	{
		auto gameObject_Camera = gameObjectManager.createGameObject("Camera");
		auto cameraInfo = make_shared<CameraInfo>(gameObject_Camera);
		gameObject_Camera->addComponent(cameraInfo);

	}

	{
		auto gameObject_Avatar = gameObjectManager.createGameObject("Avatar");
		auto player = make_shared<Player> (modelImporter.getModel("aj.fbx"),gameObject_Avatar);
		gameObject_Avatar->addComponent(player);

		//assign callback
		player->addEventHandler(inputManager, globalSetting,"front");
		player->addEventHandler(inputManager, globalSetting,"back");
		player->addEventHandler(inputManager, globalSetting,"left");
		player->addEventHandler(inputManager, globalSetting, "right");

	}

	{
		inputManager.addKey(119, "front");
		inputManager.addKey(115, "back");
		inputManager.addKey(97, "left");
		inputManager.addKey(100, "right");
	}



	//camera stuff
	{
		camera.setPosition({ 0,500,-500 });
		camera.lookAt(ofVec3f(0, 0, 0));
		camera.setFarClip(6000);
		camera.setNearClip(.5f);
		camera.toggleFixUpDirectionEnabled(); // to make the camera always up
	}

	ofSetBackgroundColor(255); //rgb
}

//--------------------------------------------------------------
void ofApp::update(){

	gameObjectManager.update();
	inputManager.update();
}

//--------------------------------------------------------------
void ofApp::draw() {

	{
		ofEnableDepthTest();//if fragment is in front or back in regards to the camera. renders only front.
		camera.begin();
		{
			light.enable();//			ofEnableLighting(); is automatically called. global lighting state is enabled. 
			{
				ofSetColor(255, 255, 255);
				gameObjectManager.draw();
			}

			light.disable(); //you might want to turn off one lightand leave the rest on do some more rendering. so not automatically called.
			ofDisableLighting();
		}
		camera.end();
		ofDisableDepthTest();
	}
}
	
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	inputManager.setKeyFromKeyCode(key, true);
	inputManager.executeCallbacks();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	inputManager.setKeyFromKeyCode(key, false);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
