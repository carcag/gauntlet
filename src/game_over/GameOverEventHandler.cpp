#include "GameOverEventHandler.hpp"
#include "StateManager.hpp"
#include "MenuState.hpp"
#include "GameOverState.hpp"
#include "PauseGameState.hpp"

GameOverEventHandler::GameOverEventHandler() {
}

GameOverEventHandler::~GameOverEventHandler() {
}

void GameOverEventHandler::HandleEvent(EventReceiver *receiver, irr::IrrlichtDevice& device, std::list<Entity *>& entities) const {
	if (receiver->IsButtonPressed(REREREMENU_BUTTON)) {
		MenuState *ms = new MenuState(device);
		StateManager::Instance()->Replace(ms);
	}
	else if (receiver->IsButtonPressed(REREREQUIT_BUTTON)) {
		device.closeDevice();
	}
}
