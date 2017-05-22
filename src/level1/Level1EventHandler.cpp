#include "Level1EventHandler.hpp"
#include "PlayerCharacter.hpp"
#include "PauseGameState.hpp"
#include "StateManager.hpp"
#include <unistd.h>

Level1EventHandler::Level1EventHandler() {
}

Level1EventHandler::~Level1EventHandler() {
}

void Level1EventHandler::HandleEvent(EventReceiver *receiver, irr::IrrlichtDevice& device, std::list<Entity *>& entities) const {
	if (receiver->IsKeyDown(irr::KEY_KEY_F)) {
		device.closeDevice();
	}
	else if (receiver->IsKeyPressed(irr::KEY_ESCAPE)) {
		irr::u16 players = 0;
		for (std::list<Entity *>::iterator ent = entities.begin(); ent != entities.end(); ent++) {
			if (PlayerCharacter *c = dynamic_cast<PlayerCharacter *>(*ent))
				players++;
		}
	 	PauseGameState *mps = new PauseGameState(device, entities);
	  	StateManager::Instance()->Push(mps);
	}
	for (std::list<Entity *>::iterator it = entities.begin(); it != entities.end(); it++) {
		if (PlayerCharacter *pc = dynamic_cast<PlayerCharacter *>(*it)) {
			pc->Events(receiver);
		}
 }
}
