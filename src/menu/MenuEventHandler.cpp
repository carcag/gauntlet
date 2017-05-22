#include "MenuEventHandler.hpp"
#include "StateManager.hpp"
#include "Level1State.hpp"
#include "MenuState.hpp"
#include <iostream>
#include <fstream>
#include <vector>

MenuEventHandler::MenuEventHandler() {
}

MenuEventHandler::~MenuEventHandler() {
}

void MenuEventHandler::HandleEvent(EventReceiver *receiver, irr::IrrlichtDevice& device, std::list<Entity *>& entities) const {
	if (receiver->IsButtonPressed(LAUNCH_BUTTON)) {
		Level1State *l1 = new Level1State(device, 1);
		StateManager::Instance()->Replace(l1);
	}
	else if (receiver->IsButtonPressed(MULTI2_BUTTON)) {
		Level1State *l1 = new Level1State(device, 2);
		StateManager::Instance()->Replace(l1);
	}
	else if (receiver->IsButtonPressed(MULTI3_BUTTON)) {
		Level1State *l1 = new Level1State(device, 3);
		StateManager::Instance()->Replace(l1);
	}
	else if (receiver->IsButtonPressed(MULTI4_BUTTON)) {
		Level1State *l1 = new Level1State(device, 4);
		StateManager::Instance()->Replace(l1);
	}
	else if (receiver->IsButtonPressed(LOAD_BUTTON)) {
	  std::fstream savefile(".save");
	  std::vector<std::string> tabinfo;
	  if (!savefile)
	    std::cerr << "fichier de sauvegarde inexistant" << std::endl;
	  else {
	    while(!savefile.eof())
	      {
	       	tabinfo.push_back("");
			getline(savefile, tabinfo.back());
			int line = tabinfo.size() - 1;
			if(tabinfo[line].empty())
		  		tabinfo.pop_back();
	      }
	  	Level1State *l1 = new Level1State(device, atoi(tabinfo[0].c_str()), tabinfo);
	  	StateManager::Instance()->Replace(l1);
	  }
	}
	else if (receiver->IsButtonPressed(QUIT_BUTTON)) {
		device.closeDevice();
	}
}
