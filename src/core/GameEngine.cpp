#include <iostream>
#include "GameEngine.hpp"

GameEngine::GameEngine() {
	std::cout << "GameEngine()" << std::endl;
	state_manager_ = StateManager::Instance();
	event_receiver_ = new EventReceiver;
	device_ = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 1080), 16, false, false, false, event_receiver_);
	if (!device_) {
		std::cerr << "GameEngine : failed to initialize irrlicht device" << std::endl;
		exit(EXIT_FAILURE);
	}
	irr::core::array<irr::SJoystickInfo> joystickInfo;
	if(device_->activateJoysticks(joystickInfo)) {
		std::cout << "Joystick support is enabled and " << joystickInfo.size() << " joystick(s) are present." << std::endl;
		for(irr::u32 joystick = 0; joystick < joystickInfo.size(); ++joystick) {
			std::cout << "Joystick " << joystick << ":" << std::endl;
			std::cout << "\tName: '" << joystickInfo[joystick].Name.c_str() << "'" << std::endl;
			std::cout << "\tAxes: " << joystickInfo[joystick].Axes << std::endl;
			std::cout << "\tButtons: " << joystickInfo[joystick].Buttons << std::endl;

			std::cout << "\tHat is: ";

			switch(joystickInfo[joystick].PovHat)
			{
			case irr::SJoystickInfo::POV_HAT_PRESENT:
				std::cout << "present" << std::endl;
				break;

			case irr::SJoystickInfo::POV_HAT_ABSENT:
				std::cout << "absent" << std::endl;
				break;

			case irr::SJoystickInfo::POV_HAT_UNKNOWN:
			default:
				std::cout << "unknown" << std::endl;
				break;
			}
		}
	} else {
		std::cout << "Joystick support is not enabled." << std::endl;
	}
	device_->setWindowCaption(L"Gauntlet - pre-alpha with weird bugs.");
}

GameEngine::~GameEngine() {
	delete state_manager_;
	delete event_receiver_;
	device_->drop();
	std::cout << "~GameEngine()" << std::endl;
}

irr::IrrlichtDevice& GameEngine::GetDevice() const {
	return (*device_);
}

bool GameEngine::Run() {
	return (device_->run() && StateManager::Instance()->HasActiveState());
}

void GameEngine::Events() {
	event_receiver_->EndEventProcess();
	if (StateManager::Instance()->HasActiveState()) {
		StateManager::Instance()->GetActiveState()->Events(event_receiver_);
	} else {
		std::cerr << "GameEngine : no active state" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void GameEngine::Update() {
	if (StateManager::Instance()->HasActiveState()) {
		StateManager::Instance()->GetActiveState()->Update();
	} else {
		std::cerr << "GameEngine : no active state" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void GameEngine::Render() {
	if (StateManager::Instance()->HasActiveState()) {
		StateManager::Instance()->GetActiveState()->Render();
	} else {
		std::cerr << "GameEngine : no active state" << std::endl;
		exit(EXIT_FAILURE);
	}
	event_receiver_->StartEventProcess();
}
