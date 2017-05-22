#include "IntroUpdateHandler.hpp"
#include "StateManager.hpp"

IntroUpdateHandler::IntroUpdateHandler() {
}

IntroUpdateHandler::~IntroUpdateHandler() {
}

void IntroUpdateHandler::HandleUpdate(std::list<Entity *>& entities) const {
	for (std::list<Entity *>::iterator it = entities.begin(); it != entities.end(); it++) {
		(*it)->Update();
	}
}
