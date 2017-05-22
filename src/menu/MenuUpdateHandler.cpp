#include "MenuUpdateHandler.hpp"
#include "StateManager.hpp"

MenuUpdateHandler::MenuUpdateHandler() {
}

MenuUpdateHandler::~MenuUpdateHandler() {
}

void MenuUpdateHandler::HandleUpdate(std::list<Entity *>& entities) const {
	for (std::list<Entity *>::iterator it = entities.begin(); it != entities.end(); it++) {
		(*it)->Update();
	}
}
