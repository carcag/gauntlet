#include "IntroEventHandler.hpp"
#include "StateManager.hpp"
#include "MenuState.hpp"

IntroEventHandler::IntroEventHandler() {
}

IntroEventHandler::~IntroEventHandler() {
}

void IntroEventHandler::HandleEvent(EventReceiver *receiver, irr::IrrlichtDevice& device, std::list<Entity *>& entities) const {
	if (receiver->IsKeyPressed(irr::KEY_RETURN)) {
		MenuState *ms = new MenuState(device);
		StateManager::Instance()->Replace(ms);
	}
	if (receiver->IsKeyPressed(irr::KEY_ESCAPE)) {
		MenuState *ms = new MenuState(device);
		StateManager::Instance()->Replace(ms);
	}
}
