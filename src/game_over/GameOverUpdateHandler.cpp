#include "GameOverUpdateHandler.hpp"
#include "StateManager.hpp"

GameOverUpdateHandler::GameOverUpdateHandler() {
}

GameOverUpdateHandler::~GameOverUpdateHandler() {
}

void GameOverUpdateHandler::HandleUpdate(std::list<Entity *>& entities) const {
	for (std::list<Entity *>::iterator it = entities.begin(); it != entities.end(); it++) {
		(*it)->Update();
	}
}
