#include <iostream>
#include "Gauntlet.hpp"
#include "IntroState.hpp"
#include "MenuState.hpp"
#include "GameEngine.hpp"

int main() {
	GameEngine *ge = new GameEngine;
	IntroState *is = new IntroState(ge->GetDevice());

	StateManager::Instance()->Push(is);
	while (ge->Run()) {
		ge->Events();
		ge->Update();
		ge->Render();
	}
	delete ge;
}
