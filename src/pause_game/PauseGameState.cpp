#include <iostream>
#include "PauseGameState.hpp"

PauseGameState::PauseGameState(irr::IrrlichtDevice& device) : IState(device) {
	event_handler_ = new PauseGameEventHandler;
	update_handler_ = new PauseGameUpdateHandler;
	render_handler_ = new PauseGameRenderHandler;
	init();
	std::cout << "PauseGameState()" << std::endl;
}

PauseGameState::PauseGameState(irr::IrrlichtDevice& device, std::list<Entity *>& entities) : IState(device, entities) {
	event_handler_ = new PauseGameEventHandler;
	update_handler_ = new PauseGameUpdateHandler;
	render_handler_ = new PauseGameRenderHandler;
	init();
	std::cout << "PauseGameState()" << std::endl;
}

PauseGameState::~PauseGameState() {
	drop();
	delete event_handler_;
	delete update_handler_;
	delete render_handler_;
	std::cout << "~PauseGameState()" << std::endl;
}

void PauseGameState::init() {
	irr::gui::IGUIEnvironment *env = device_.getGUIEnvironment();
	device_.getCursorControl()->setVisible(true);

	irr::gui::IGUISkin *skin = env->getSkin();
	irr::gui::IGUIFont *font = env->getFont("media/fontlucida.png");
	if (font)
		skin->setFont(font);

	restart_ = env->addButton(irr::core::rect<irr::s32>(1300, 250, 1600, 300), 0, RELAUNCH_BUTTON, L"Retourner au jeu");
	save_ = env->addButton(irr::core::rect<irr::s32>(1300, 350, 1600, 400), 0, SAVE_BUTTON, L"Sauvegarder la partie");
	quit_ = env->addButton(irr::core::rect<irr::s32>(1300, 450, 1600, 500), 0, REQUIT_BUTTON, L"Quitter le jeu");
	menu_ = env->addButton(irr::core::rect<irr::s32>(1300, 550, 1600, 600), 0, MENU_BUTTON, L"Retourner au menu Titre");
}

void PauseGameState::drop() {
	irr::gui::IGUIEnvironment *env = device_.getGUIEnvironment();
	device_.getCursorControl()->setVisible(false);
	env->clear();
	// restart_->remove();
	// quit_->remove();
	// menu_->remove();
}

void PauseGameState::Events(EventReceiver *receiver) {
  event_handler_->HandleEvent(receiver, device_, entities_);
}

void PauseGameState::Update() {
	update_handler_->HandleUpdate(entities_);
}

void PauseGameState::Render() {
	render_handler_->HandleRender(device_);
}
