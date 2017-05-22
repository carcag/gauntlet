#include "PauseGameUpdateHandler.hpp"
#include "StateManager.hpp"

PauseGameUpdateHandler::PauseGameUpdateHandler() {
}

PauseGameUpdateHandler::~PauseGameUpdateHandler() {
}

void PauseGameUpdateHandler::HandleUpdate(std::list<Entity *>& entities) const {
	for (std::list<Entity *>::iterator it = entities.begin(); it != entities.end(); it++) {
		(*it)->Update();
	}
}
