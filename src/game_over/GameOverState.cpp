#include <iostream>
#include "GameOverState.hpp"

GameOverState::GameOverState(irr::IrrlichtDevice& device) : IState(device) {
	event_handler_ = new GameOverEventHandler;
	update_handler_ = new GameOverUpdateHandler;
	render_handler_ = new GameOverRenderHandler;
	init();
	std::cout << "GameOverState()" << std::endl;
}

GameOverState::~GameOverState() {
	drop();
	delete event_handler_;
	delete update_handler_;
	delete render_handler_;
	std::cout << "~GameOverState()" << std::endl;
}

void GameOverState::init() {
	irr::gui::IGUIEnvironment *env = device_.getGUIEnvironment();
	device_.getCursorControl()->setVisible(true);

	irr::gui::IGUISkin *skin = env->getSkin();
	irr::gui::IGUIFont *font = env->getFont("media/fontlucida.png");
	if (font)
		skin->setFont(font);

	menu_ = env->addButton(irr::core::rect<irr::s32>(860, 650, 1060, 700), 0, REREREMENU_BUTTON, L"Retourner au menu titre");
	quit_ = env->addButton(irr::core::rect<irr::s32>(860, 750, 1060, 800), 0, REREREQUIT_BUTTON, L"Quitter le jeu");
}

void GameOverState::drop() {
	irr::gui::IGUIEnvironment *env = device_.getGUIEnvironment();

	for (std::list<Entity *>::iterator it = entities_.begin(); it != entities_.end(); it++) {
		delete *it;
	}
}

void GameOverState::Events(EventReceiver *receiver) {
	event_handler_->HandleEvent(receiver, device_, entities_);
}

void GameOverState::Update() {
	update_handler_->HandleUpdate(entities_);
}

void GameOverState::Render() {
	render_handler_->HandleRender(device_);
}
