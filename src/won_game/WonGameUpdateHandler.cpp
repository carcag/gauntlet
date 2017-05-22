#include "WonGameUpdateHandler.hpp"
#include "StateManager.hpp"

WonGameUpdateHandler::WonGameUpdateHandler() {
}

WonGameUpdateHandler::~WonGameUpdateHandler() {
}

void WonGameUpdateHandler::HandleUpdate(std::list<Entity *>& entities) const {
	for (std::list<Entity *>::iterator it = entities.begin(); it != entities.end(); it++) {
		(*it)->Update();
	}
}
