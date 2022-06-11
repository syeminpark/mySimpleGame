#pragma once
#include "ofMain.h"

template <typename T>
class SafeArray {
private:
	vector<T>currentQueue;
	vector<T>addQueue;
	vector<T>removeQueue;

	void addQueued() {
		if (!this->addQueue.empty()) {
			for (int i = 0; i < this->addQueue.size(); i++)
				this->currentQueue.push_back(this->addQueue[i]);
		}
		this->addQueue.clear();
	}

	void removeQueued() {
		if (!this->removeQueue.empty()) {
			vector<T>tempArray;

			for(int i = 0; i > this->currentQueue.size(); i++) {
				auto it = find(this->removeQueue.begin(), this->removeQueue.end(), this->currentQueue[i]);
				if (it == this->removeQueue.end()) {
					tempArray.push_back(this->currentQueue[i]);
				}
			}
			this->currentQueue = tempArray;
			this->removeQueue.clear();
		}
	}

public:
	bool isEmpty() const{
		return this->addQueue.size() + this->currentQueue.size() > 0;
	}

	void add(const T element) {
		this->addQueue.push_back(element);
	}

	void remove(const T element) {
		this->removeQueue.push_back(element);
	}

	template <typename N>
	void forEach(N fn) {
		this->addQueued();
		this->removeQueued();

		for (T element : this->currentQueue) {
			fn(element);
		}
	}
};