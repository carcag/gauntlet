#include <iostream>
#include <fstream>
#include "MenuState.hpp"


MenuState::MenuState(irr::IrrlichtDevice& device) : IState(device) {
	event_handler_ = new MenuEventHandler;
	update_handler_ = new MenuUpdateHandler;
	render_handler_ = new MenuRenderHandler;
	init();
	std::cout << "MenuState()" << std::endl;
}

MenuState::~MenuState() {
	drop();
	delete event_handler_;
	delete update_handler_;
	delete render_handler_;
	std::cout << "~MenuState()" << std::endl;
}

void MenuState::init() {
	device_.getCursorControl()->setVisible(true);
	// mixer.LoadMusic(MENU);
	// mixer.PlayMusic();
	irr::gui::IGUIEnvironment *env = device_.getGUIEnvironment();
	env->clear();
	device_.setWindowCaption(L"Welcome !");

	irr::gui::IGUISkin *skin = env->getSkin();
	irr::gui::IGUIFont *font = env->getFont("media/fontlucida.png");
	if (font)
		skin->setFont(font);

	start_ = env->addButton(irr::core::rect<irr::s32>(1300, 250, 1600, 300), 0, LAUNCH_BUTTON, L"Lancer le jeu");
	multi2_ = env->addButton(irr::core::rect<irr::s32>(1300, 350, 1600, 400), 0, MULTI2_BUTTON, L"Lancer le jeu en mode 2 joueurs");
	multi3_ = env->addButton(irr::core::rect<irr::s32>(1300, 450, 1600, 500), 0, MULTI3_BUTTON, L"Lancer le jeu en mode 3 joueurs");
	multi4_ = env->addButton(irr::core::rect<irr::s32>(1300, 550, 1600, 600), 0, MULTI4_BUTTON, L"Lancer le jeu en mode 4 joueurs");
	std::fstream savefile(".save");
	if (!savefile) {
		quit_ = env->addButton(irr::core::rect<irr::s32>(1300, 650, 1600, 700), 0, QUIT_BUTTON, L"Quitter le jeu");
	}
	else  {
		load_ = env->addButton(irr::core::rect<irr::s32>(1300, 650, 1600, 700), 0, LOAD_BUTTON, L"Charger une partie");
		quit_ = env->addButton(irr::core::rect<irr::s32>(1300, 750, 1600, 800), 0, QUIT_BUTTON, L"Quitter le jeu");
	}
}

void MenuState::drop() {
	irr::gui::IGUIEnvironment *env = device_.getGUIEnvironment();

	// mixer.StopMusic();
	for (std::list<Entity *>::iterator it = entities_.begin(); it != entities_.end(); it++) {
		delete *it;
	}
	env->clear();
	// start_->remove();
	// quit_->remove();
}

void MenuState::Events(EventReceiver *receiver) {
	event_handler_->HandleEvent(receiver, device_, entities_);
}

void MenuState::Update() {
	update_handler_->HandleUpdate(entities_);
}

void MenuState::Render() {
	render_handler_->HandleRender(device_);
}
