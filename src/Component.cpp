
#include "Component.h"
#include "GameObject.h"

	Component::Component(shared_ptr<GameObject> gameObject, string name) {
		this->gameObject = gameObject;
		this->name = name;
	}

	//--------------------------------------------------------------
	string Component::getName() const{
		return this->name; 
	}

	//-----------------w---------------------------------------------w