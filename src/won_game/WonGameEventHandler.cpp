#include "WonGameEventHandler.hpp"
#include "StateManager.hpp"
#include "MenuState.hpp"
#include "PauseGameState.hpp"
#include "WonGameState.hpp"

WonGameEventHandler::WonGameEventHandler() {
}

WonGameEventHandler::~WonGameEventHandler() {
}

void WonGameEventHandler::HandleEvent(EventReceiver *receiver, irr::IrrlichtDevice& device, std::list<Entity *>& entities) const {
	if (receiver->IsButtonPressed(REREMENU_BUTTON)) {
		MenuState *ms = new MenuState(device);
		StateManager::Instance()->Replace(ms);
	}
	else if (receiver->IsButtonPressed(REREQUIT_BUTTON)) {
		device.closeDevice();
	}
}
