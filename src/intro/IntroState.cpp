#include <iostream>
#include "IntroState.hpp"

IntroState::IntroState(irr::IrrlichtDevice& device) : IState(device) {
	event_handler_ = new IntroEventHandler;
	update_handler_ = new IntroUpdateHandler;
	render_handler_ = new IntroRenderHandler;
	init();
	std::cout << "IntroState()" << std::endl;
}

IntroState::~IntroState() {
	drop();
	delete event_handler_;
	delete update_handler_;
	delete render_handler_;
	std::cout << "~IntroState()" << std::endl;
}

void IntroState::init() {
}

void IntroState::drop() {
	for (std::list<Entity *>::iterator it = entities_.begin(); it != entities_.end(); it++) {
		delete *it;
	}
}

void IntroState::Events(EventReceiver *receiver) {
  event_handler_->HandleEvent(receiver, device_, entities_);
}

void IntroState::Update() {
	update_handler_->HandleUpdate(entities_);
}

void IntroState::Render() {
	render_handler_->HandleRender(device_);
}
