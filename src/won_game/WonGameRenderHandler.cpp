#include "WonGameRenderHandler.hpp"
#include "WonGameState.hpp"

WonGameRenderHandler::WonGameRenderHandler() {
}

WonGameRenderHandler::~WonGameRenderHandler() {
}

void WonGameRenderHandler::HandleRender(irr::IrrlichtDevice& device) const {
	irr::video::IVideoDriver* driver = device.getVideoDriver();
	//irr::scene::ISceneManager* smgr = device.getSceneManager();
	irr::gui::IGUIEnvironment* env = device.getGUIEnvironment();

	irr::video::ITexture *image2 = driver->getTexture("media/win.jpg");
	irr::core::dimension2d<unsigned int> size = image2->getSize();
	irr::core::position2d<irr::s32> position3;
	position3.X = 710;
	position3.Y = 100;
	driver->beginScene(true, true, irr::video::SColor (255,255,255,255));
	driver->draw2DImage(image2, position3);
	//smgr->drawAll();
	env->drawAll();
	driver->endScene();
}
