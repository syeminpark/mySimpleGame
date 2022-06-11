#pragma once
#include "ofMain.h"
#include "InputState.h"

class InputManager {
private:
	map<string, InputState>keyState;
	map<int, string> keyMap;

	map<int, string>::iterator keyMapIterator;
	map<string, InputState>::iterator keyStateIterator;
	
	map<string, function<void()>> assignedCallbacks;

	void setKey(string keyName, bool pressed);
	bool isPressed(string name);

public: 
	void addKey(int keyCode, string name);
	void setKeyFromKeyCode(int keyCode, bool pressed);
	void assignCallback(string name, function<void()>callback);
	void executeCallbacks();
	void update();
};



