#pragma once

struct InputState {
	bool down;
	bool justPressed;

	InputState() {};
	InputState(bool down, bool justPressed) :down(down), justPressed(justPressed) {};
};
