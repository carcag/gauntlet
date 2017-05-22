#include "PauseGameEventHandler.hpp"
#include "StateManager.hpp"
#include "PlayerCharacter.hpp"
#include "MenuState.hpp"
#include "PauseGameState.hpp"
#include "Level1State.hpp"
#include "FindFile.hpp"
#include <iostream>

PauseGameEventHandler::PauseGameEventHandler() {
}

PauseGameEventHandler::~PauseGameEventHandler() {
}

void PauseGameEventHandler::HandleEvent(EventReceiver *receiver, irr::IrrlichtDevice& device, std::list<Entity *>& entities) const {
	if (receiver->IsButtonPressed(RELAUNCH_BUTTON)) {
		StateManager::Instance()->Pop();
	}
	else if (receiver->IsButtonPressed(REQUIT_BUTTON)) {
	 	device.closeDevice();
	}
	else if (receiver->IsButtonPressed(SAVE_BUTTON)) {
	  remove(".save");
	  irr::u16 players = 0;
	  for (std::list<Entity *>::iterator ent = entities.begin(); ent != entities.end(); ent++) {
		if (PlayerCharacter *c = dynamic_cast<PlayerCharacter *>(*ent))
			players++;
		}
	  saveInfoInFile(".save", players);
	  for (std::list<Entity *>::iterator ite = entities.begin(); ite != entities.end(); ite++) {
	    if (Character *c = dynamic_cast<Character *>(*ite)) {
	      saveInfoInFile(".save", c->GetLife());
	      saveInfoInFile(".save", c->GetPos().X);
	      saveInfoInFile(".save", c->GetPos().Y);
	      saveInfoInFile(".save", c->GetPos().Z);
	      saveInfoInFile(".save", c->GetRot().X);
	      saveInfoInFile(".save", c->GetRot().Y);
	      saveInfoInFile(".save", c->GetRot().Z);
	    }
       }
	  }
	else if (receiver->IsButtonPressed(MENU_BUTTON)) {
		StateManager::Instance()->Pop();
		MenuState *ms = new MenuState(device);
		StateManager::Instance()->Replace(ms);
	}
	else if (receiver->IsKeyPressed(irr::KEY_ESCAPE)) {
		StateManager::Instance()->Pop();
	}
}
