#include "GameOverRenderHandler.hpp"
#include "GameOverState.hpp"

GameOverRenderHandler::GameOverRenderHandler() {
}

GameOverRenderHandler::~GameOverRenderHandler() {
}

void GameOverRenderHandler::HandleRender(irr::IrrlichtDevice& device) const {
	irr::video::IVideoDriver* driver = device.getVideoDriver();
	//irr::scene::ISceneManager* smgr = device.getSceneManager();
	irr::gui::IGUIEnvironment* env = device.getGUIEnvironment();

	irr::video::ITexture *image2 = driver->getTexture("media/loose.jpg");
	irr::core::dimension2d<unsigned int> size = image2->getSize();
	irr::core::position2d<irr::s32> position3;
	position3.X = 672;
	position3.Y = 50;
	driver->beginScene(true, true, irr::video::SColor (255,255,255,255));
	driver->draw2DImage(image2, position3);
	//smgr->drawAll();
	env->drawAll();
	driver->endScene();
}
