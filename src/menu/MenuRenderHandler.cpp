#include "MenuRenderHandler.hpp"
#include "StateManager.hpp"
#include "MenuState.hpp"

MenuRenderHandler::MenuRenderHandler() {
}

MenuRenderHandler::~MenuRenderHandler() {
}

void MenuRenderHandler::HandleRender(irr::IrrlichtDevice& device) const {
	irr::video::IVideoDriver* driver = device.getVideoDriver();
	//irr::scene::ISceneManager* smgr = device.getSceneManager();
	irr::gui::IGUIEnvironment* env = device.getGUIEnvironment();

	irr::video::ITexture *image = driver->getTexture("media/MenuBackGround.jpg");
	irr::core::dimension2d<unsigned int> taille = image->getSize();
	irr::core::position2d<irr::s32> position0;
	position0.X = 0;
	position0.Y = 0;
	irr::core::position2d<irr::s32> position1;
	position1.X = taille.Width;
	position1.Y = taille.Height;
	irr::core::rect<irr::s32> rectangle;
	rectangle.UpperLeftCorner = position0;
	rectangle.LowerRightCorner = position1;
	driver->beginScene(true, true, irr::video::SColor (0,120,120,120));
	driver->draw2DImage(image, position0, rectangle, 0, irr::video::SColor (255,255,255,255), true);
	//smgr->drawAll();
	env->drawAll();
	driver->endScene();
}
