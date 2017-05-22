#include "PauseGameRenderHandler.hpp"
#include "PauseGameState.hpp"

PauseGameRenderHandler::PauseGameRenderHandler() {
}

PauseGameRenderHandler::~PauseGameRenderHandler() {
}

void PauseGameRenderHandler::HandleRender(irr::IrrlichtDevice& device) const {
	irr::video::IVideoDriver* driver = device.getVideoDriver();
	irr::gui::IGUIEnvironment* env = device.getGUIEnvironment();
	env->drawAll();
	driver->endScene();
}
