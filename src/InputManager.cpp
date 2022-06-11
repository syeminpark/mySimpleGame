#include "InputManager.h"

//--------------------------------------------------------------
void InputManager::addKey(int keyCode, string name) {
	this->keyState.insert(make_pair(name, InputState(false, false)));
	this->keyMap.insert(make_pair(keyCode, name));
}

//--------------------------------------------------------------
void InputManager::setKey(string keyName, bool pressed) {
	this->keyState[keyName].justPressed = pressed && !this->keyState[keyName].down;
	this->keyState[keyName].down = pressed;
}


//--------------------------------------------------------------
void InputManager::setKeyFromKeyCode(int keyCode, bool pressed) {
	this->keyMapIterator = this->keyMap.find(keyCode);
	if (this->keyMapIterator == this->keyMap.end()) {
		cout << "keyCode: " << keyCode << "not added to keyMap Array. use addKey Function" << endl;
		return;
	}

	const string keyName = this->keyMap[keyCode];
	this->setKey(keyName, pressed);
}

//--------------------------------------------------------------
bool InputManager::isPressed(string name) {
		this->keyStateIterator = this->keyState.find(name);
		if (this->keyStateIterator != this->keyState.end()){
			return this->keyState[name].down;
		}
		return false;
}

//--------------------------------------------------------------
void InputManager::assignCallback(string name, function<void()>callback) {
	this->assignedCallbacks.insert(make_pair(name, callback));
	cout << this->assignedCallbacks.size() << endl;

}

//--------------------------------------------------------------
void InputManager::executeCallbacks() {
	for (auto const &callback : this->assignedCallbacks) {
		cout << callback.first << endl;
		if (isPressed(callback.first)) {
			cout << "isPressed" << endl;
			callback.second();
		}
	}
}

//--------------------------------------------------------------
void InputManager::update() {
	for (auto& keyState : this->keyState) {
		if (keyState.second.justPressed) {
			keyState.second.justPressed = false;
		}
	}
}




//--------------------------------------------------------------