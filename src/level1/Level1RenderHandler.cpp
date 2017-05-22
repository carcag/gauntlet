#include "Level1RenderHandler.hpp"
#include "HUD.hpp"

Level1RenderHandler::Level1RenderHandler() {
}

Level1RenderHandler::~Level1RenderHandler() {
}

void Level1RenderHandler::HandleRender(irr::IrrlichtDevice& device, HUD *hud[4], irr::u16 nb_players, irr::scene::ICameraSceneNode *camera[4]) const {
	irr::video::IVideoDriver* driver = device.getVideoDriver();
	irr::scene::ISceneManager* smgr = device.getSceneManager();
	driver->beginScene(true, true, irr::video::SColor(0,0,0,0));

	if (nb_players > 1) {
		if (nb_players == 2)
			render2Player(device, hud, camera);
		if (nb_players == 3)
			render3Player(device, hud, camera);
		if (nb_players == 4)
			render4Player(device, hud, camera);
	} else {
		smgr->setActiveCamera(camera[0]);
		smgr->drawAll();
		hud[0]->Display();
	}
	driver->setViewPort(irr::core::rect<irr::s32>(0,0,1920,1080));
	driver->endScene();
}

void Level1RenderHandler::render2Player(irr::IrrlichtDevice& device, HUD *hud[4], irr::scene::ICameraSceneNode *camera[4]) const {
	irr::video::IVideoDriver* driver = device.getVideoDriver();
	irr::scene::ISceneManager* smgr = device.getSceneManager();

	smgr->setActiveCamera(camera[0]);
	driver->setViewPort(irr::core::rect<irr::s32>(0,0,1920,1080/2));
	smgr->drawAll();
	hud[0]->Display();

	smgr->setActiveCamera(camera[1]);
	driver->setViewPort(irr::core::rect<irr::s32>(0,1080/2,1920,1080));
	smgr->drawAll();
	hud[1]->Display();
}

void Level1RenderHandler::render3Player(irr::IrrlichtDevice& device, HUD *hud[4], irr::scene::ICameraSceneNode *camera[4]) const {
	irr::video::IVideoDriver* driver = device.getVideoDriver();
	irr::scene::ISceneManager* smgr = device.getSceneManager();

	smgr->setActiveCamera(camera[0]);
	driver->setViewPort(irr::core::rect<irr::s32>(0,0,1920,1080/2));
	smgr->drawAll();
	hud[0]->Display();

	smgr->setActiveCamera(camera[1]);
	driver->setViewPort(irr::core::rect<irr::s32>(0,1080/2,1920/2,1080));
	smgr->drawAll();
	hud[1]->Display();

	smgr->setActiveCamera(camera[2]);
	driver->setViewPort(irr::core::rect<irr::s32>(1920/2,1080/2,1920,1080));
	smgr->drawAll();
	hud[2]->Display();
}

void Level1RenderHandler::render4Player(irr::IrrlichtDevice& device, HUD *hud[4], irr::scene::ICameraSceneNode *camera[4]) const {
	irr::video::IVideoDriver* driver = device.getVideoDriver();
	irr::scene::ISceneManager* smgr = device.getSceneManager();

	smgr->setActiveCamera(camera[0]);
	driver->setViewPort(irr::core::rect<irr::s32>(0,0,1920/2,1080/2));
	smgr->drawAll();
	hud[0]->Display();

	smgr->setActiveCamera(camera[1]);
	driver->setViewPort(irr::core::rect<irr::s32>(0,1080/2,1920/2,1080));
	smgr->drawAll();
	hud[1]->Display();

	smgr->setActiveCamera(camera[2]);
	driver->setViewPort(irr::core::rect<irr::s32>(1920/2,0,1920,1080/2));
	smgr->drawAll();
	hud[2]->Display();

	smgr->setActiveCamera(camera[3]);
	driver->setViewPort(irr::core::rect<irr::s32>(1920/2,1080/2,1920,1080));
	smgr->drawAll();
	hud[3]->Display();
}
