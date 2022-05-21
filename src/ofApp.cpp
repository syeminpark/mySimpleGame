#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofDisableArbTex(); //default OF uses rectangular textures instead of 2D textures. legacy way. 

	ofSetFrameRate(30); //set frame rate 
	light.setPosition(-300, 300, 300);

	{
		ModelImporter modelImporter;
		modelImporter.import({ "aj.fbx","kaya.fbx","ty.fbx" ,"vegas.fbx" });
	
		auto gameObject = gameObjectManager.createGameObject();
		auto player = make_shared<Player> (modelImporter.getModel("aj.fbx"),gameObject);
		gameObject->addComponent(player);
	}

	//camera stuff
	{
		camera.setPosition({ 0,200,300 });
		camera.lookAt(ofVec3f(0, 0, 0));
		camera.setFarClip(6000);
		camera.setNearClip(.5f);
		camera.toggleFixUpDirectionEnabled(); // to make the camera always up
	}

	ofSetBackgroundColor(100, 100, 100); //rgb
}

//--------------------------------------------------------------
void ofApp::update(){

	gameObjectManager.update();
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
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
