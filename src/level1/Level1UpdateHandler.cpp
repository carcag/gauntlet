#include "Level1UpdateHandler.hpp"
#include "StateManager.hpp"
#include "Character.hpp"
#include "PlayerCharacter.hpp"
#include "DestructibleObject.hpp"
#include <iostream>

Level1UpdateHandler::Level1UpdateHandler() {
}

Level1UpdateHandler::~Level1UpdateHandler() {
}

void Level1UpdateHandler::HandleUpdate(std::list<Entity *>& entities) const {
	for (std::list<Entity *>::iterator it = entities.begin(); it != entities.end(); it++) {
		(*it)->Update();
		if (Character *c = dynamic_cast<Character *>(*it)) {
			if (PlayerCharacter *c = dynamic_cast<PlayerCharacter *>(*it)) {
				continue;
			}
			if (c->GetState() == Character::DEAD) {
				it = entities.erase(it);
				c->Remove();
				delete c;
				return;
			}
		} else if (DestructibleObject *d = dynamic_cast<DestructibleObject *>(*it)) {
			if (d->GetState() == DestructibleObject::DESTROYED) {
				it = entities.erase(it);
				delete d;
				return;
			}
		}
	}
}
