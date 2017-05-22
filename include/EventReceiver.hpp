#ifndef EVENTRECEIVER_HPP_
# define EVENTRECEIVER_HPP_

# include "irrlicht.h"

class EventReceiver : public irr::IEventReceiver {
private:
	enum KeyState {
		UP,
		DOWN,
		PRESSED,
		RELEASED
	};

	enum ProcessState {
		STARTED,
		ENDED
	};

	KeyState keys_state_[irr::KEY_KEY_CODES_COUNT];
	ProcessState process_state_;
	irr::SEvent::SJoystickEvent joystick_state_;
	bool button_is_pressed_[2];

public:
 	EventReceiver();
 	~EventReceiver();

	void StartEventProcess();
	void EndEventProcess();

	bool OnEvent(const irr::SEvent& event);

	bool IsKeyPressed(irr::EKEY_CODE keyCode);
	bool IsKeyDown(irr::EKEY_CODE keyCode);
	bool IsKeyUp(irr::EKEY_CODE keyCode);
	bool IsKeyReleased(irr::EKEY_CODE keyCode);

	bool IsButtonPressed(int id);

	const irr::SEvent::SJoystickEvent& GetJoystickState() const;
};

#endif /* !EVENTRECEIVER_HPP_ */
