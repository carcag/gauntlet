#include <iostream>
#include "WonGameState.hpp"

WonGameState::WonGameState(irr::IrrlichtDevice& device) : IState(device) {
	event_handler_ = new WonGameEventHandler;
	update_handler_ = new WonGameUpdateHandler;
	render_handler_ = new WonGameRenderHandler;
	init();
	std::cout << "WonGameState()" << std::endl;
}

WonGameState::~WonGameState() {
	drop();
	delete event_handler_;
	delete update_handler_;
	delete render_handler_;
	std::cout << "~WonGameState()" << std::endl;
}

void WonGameState::init() {
	irr::gui::IGUIEnvironment *env = device_.getGUIEnvironment();
	device_.getCursorControl()->setVisible(true);

	irr::gui::IGUISkin *skin = env->getSkin();
	irr::gui::IGUIFont *font = env->getFont("media/fontlucida.png");
	if (font)
		skin->setFont(font);

	menu_ = env->addButton(irr::core::rect<irr::s32>(860, 650, 1060, 700), 0, REREMENU_BUTTON, L"Retourner au menu titre");
	quit_ = env->addButton(irr::core::rect<irr::s32>(860, 750, 1060, 800), 0, REREQUIT_BUTTON, L"Quitter le jeu");
}

void WonGameState::drop() {
	irr::gui::IGUIEnvironment *env = device_.getGUIEnvironment();

	for (std::list<Entity *>::iterator it = entities_.begin(); it != entities_.end(); it++) {
		delete *it;
	}
}

void WonGameState::Events(EventReceiver *receiver) {
	event_handler_->HandleEvent(receiver, device_, entities_);
}

void WonGameState::Update() {
	update_handler_->HandleUpdate(entities_);
}

void WonGameState::Render() {
	render_handler_->HandleRender(device_);
}
