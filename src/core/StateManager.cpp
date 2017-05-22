#include <iostream>
#include "StateManager.hpp"

StateManager::StateManager() {
	std::cout << "StateManager()" << std::endl;
}

StateManager *StateManager::Instance() {
	static StateManager *instance = new StateManager();
	return instance;
}

StateManager::~StateManager() {
	while (!states_.empty())
		Pop();
	std::cout << "~StateManager()" << std::endl;
}

void StateManager::Replace(IState *state) {
	if (!states_.empty())
		Pop();
	states_.push(state);
}

void StateManager::Push(IState *state) {
	states_.push(state);
}

void StateManager::Pop() {
	delete states_.top();
	states_.pop();
}

bool StateManager::HasActiveState() const {
	return (!states_.empty());
}

IState *StateManager::GetActiveState() {
	return (states_.top());
}
