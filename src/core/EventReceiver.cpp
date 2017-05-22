#include "EventReceiver.hpp"

EventReceiver::EventReceiver() {
	for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; i++)
		keys_state_[i] = UP;
}

EventReceiver::~EventReceiver() {
}

void EventReceiver::StartEventProcess() {
	process_state_ = STARTED;
	for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; i ++) {
		if (keys_state_[i] == RELEASED)
			keys_state_[i] = UP;
		else if (keys_state_[i] == PRESSED)
			keys_state_[i] = DOWN;
	}
	for (irr::u32 t = 0; t < 5; t++)
		button_is_pressed_[t] = false;
}

void EventReceiver::EndEventProcess() {
	process_state_ = ENDED;
}

bool EventReceiver::OnEvent(const irr::SEvent& event) {
	bool processed = false;

	if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick == 0) {
		joystick_state_ = event.JoystickEvent;
	}

	if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
		if (process_state_ == STARTED) {
			if (event.KeyInput.PressedDown == true) {
				if (keys_state_[event.KeyInput.Key] != DOWN)
					keys_state_[event.KeyInput.Key] = PRESSED;
				else
					keys_state_[event.KeyInput.Key] = DOWN;
			} else {
				if (keys_state_[event.KeyInput.Key] != UP)
					keys_state_[event.KeyInput.Key] = RELEASED;
			}
		}
		processed = true;
	}

	if (event.EventType == irr::EET_GUI_EVENT) {
		if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
			button_is_pressed_[event.GUIEvent.Caller->getID()] = true;
		processed = true;
	}
	// return (processed); turned off for the free camera (debug)
	return (false); //
}

bool EventReceiver::IsKeyPressed(irr::EKEY_CODE keyCode) {
	return ((keys_state_[keyCode] == PRESSED) ? true : false);
}

bool EventReceiver::IsKeyDown(irr::EKEY_CODE keyCode) {
	return ((keys_state_[keyCode] == PRESSED
		|| keys_state_[keyCode] == DOWN) ? true : false);
}


bool EventReceiver::IsKeyReleased(irr::EKEY_CODE keyCode) {
	return ((keys_state_[keyCode] == RELEASED) ? true : false);
}

bool EventReceiver::IsKeyUp(irr::EKEY_CODE keyCode) {
	return ((keys_state_[keyCode] == RELEASED
		|| keys_state_[keyCode] == UP) ? true : false);
}

bool EventReceiver::IsButtonPressed(int id) {
	return (button_is_pressed_[id]);
}

const irr::SEvent::SJoystickEvent& EventReceiver::GetJoystickState() const {
	return (joystick_state_);
}
