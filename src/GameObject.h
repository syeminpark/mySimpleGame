#pragma once
#include "ofMain.h"
#include "Component.h"

//entity component system 
class GameObject {
private:
	string name;
	vector<shared_ptr<Component>> components;
public:

	GameObject(string name) :name(name) {};

	template <typename T>
	T getComponent(string name) const {
		for (int i = 0; i < this->components.size(); i++) {
			if (this->components[i].getName() == name) {
				T object = dynamic_pointer_cast<T>(this->components[i]);
				if (object) {
					return object;
				}
			}
		}
	}

	template <typename T>
	void addComponent(const T object) {
		this->components.push_back(dynamic_pointer_cast<Component>(object));
	}


	template <typename T>
	void removeComponent(const T object) {
		auto it = find(this->components.begin(), this->components.end(), dynamic_pointer_cast<Component>(object));
		if (it != this->components.end()) {
			this->components.erase(it);
		}
	}

	template <typename T>
	void removeComponent(string name) {
		for (int i = 0; i < this->components.size(); i++) {
			if (this->components[i].getName() == name) {
				this->components.erase(i);
			}
		}
	}

	void update() {
		for (auto component : this->components) {
			component->update();
		}
	}
	void draw() {
		for (auto component : this->components) {
			component->draw();
		}
	}
};
