#include <iostream>
#include "Level1State.hpp"
#include "PlayerCharacter.hpp"
#include "NonPlayerCharacter.hpp"
#include "DestructibleObject.hpp"
#include "WonGameState.hpp"
#include "GameOverState.hpp"
#include "StateManager.hpp"
#include "AI.hpp"

Level1State::Level1State(irr::IrrlichtDevice& device, irr::u16 players_nb = 1) : GameState(device, players_nb) {
	event_handler_ = new Level1EventHandler;
	update_handler_ = new Level1UpdateHandler;
	render_handler_ = new Level1RenderHandler;
	proj_mngr_ = new ProjectileManager(device_, entities_);
	AI_mngr_ = new AI(entities_);
	players_nb_ = players_nb;
	for (int i = 0; i < players_nb_; i++) {
		huds_[i] = new HUD;
		LifeBar *lb = new LifeBar(*(device_.getVideoDriver()));
		huds_[i]->SetLifeBarModule(lb);
	}
	init();
	std::cout << "Level1State()" << std::endl;
}

Level1State::Level1State(irr::IrrlichtDevice& device, irr::u16 players_nb, std::vector<std::string> tabinfo) : GameState(device, players_nb) {
	event_handler_ = new Level1EventHandler;
	update_handler_ = new Level1UpdateHandler;
	render_handler_ = new Level1RenderHandler;
	proj_mngr_ = new ProjectileManager(device_, entities_);
	AI_mngr_ = new AI(entities_);
	players_nb_ = players_nb;
	for (int i = 0; i < players_nb_; i++) {
		huds_[i] = new HUD;
		LifeBar *lb = new LifeBar(*(device_.getVideoDriver()));
		huds_[i]->SetLifeBarModule(lb);
	}
	initLoad(tabinfo);
	std::cout << "Level1State()" << std::endl;
}

Level1State::~Level1State() {
	drop();
	delete event_handler_;
	delete update_handler_;
	delete render_handler_;
	delete proj_mngr_;
	delete AI_mngr_;
	for (int i = 0; i < players_nb_; i++) {
		delete huds_[i];
	}
	std::cout << "~Level1State()" << std::endl;
}

void Level1State::genMap(irr::scene::IMetaTriangleSelector* metaSelector, std::list<PowerUp *>& powerups_)
{
	irr::video::IVideoDriver *driver = device_.getVideoDriver();
	irr::scene::ISceneManager *smgr = device_.getSceneManager();

	// Terrain
	irr::scene::ITerrainSceneNode *terrain = smgr->addTerrainSceneNode("media/heightmap.bmp", 0, -1, irr::core::vector3df(-5000.f, 0.f, -5000.f), irr::core::vector3df(0.f, 0.f, 0.f), irr::core::vector3df(50.f, 0.0f, 50.f));
	terrain->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	terrain->setMaterialTexture(0, driver->getTexture("media/texture1.jpg"));
	terrain->setMaterialTexture(1, driver->getTexture("media/texture2.jpg"));
	terrain->setMaterialType(irr::video::EMT_DETAIL_MAP);
	terrain->scaleTexture(5.0f, 100.0f);
	// Collisions
	irr::scene::ITriangleSelector *selector1 = smgr->createTerrainTriangleSelector(terrain, 0);
	terrain->setTriangleSelector(selector1);
	metaSelector->addTriangleSelector(selector1);


	// ADD WALLS
	irr::scene::IMesh *mesh = smgr->getMesh("media/wall.3ds");
	irr::scene::ISceneNode *wallLeft = 0;
	irr::scene::ISceneNode *wallRight = 0;
	irr::scene::ISceneNode *wallUp = 0;
	irr::scene::ISceneNode *wallDown = 0;

	irr::scene::ISceneNode *wall_Spawn_Left = 0;
	irr::scene::ISceneNode *wall_Spawn_Left2 = 0;
	irr::scene::ISceneNode *wall_Spawn_Left2_2 = 0;

	irr::scene::ISceneNode *wall_Spawn_Right = 0;
	irr::scene::ISceneNode *wall_Spawn_Right2 = 0;
	irr::scene::ISceneNode *wall_Spawn_Right2_2 = 0;

	irr::scene::ISceneNode *wall_Spawn_LeftBar1 = 0;
	irr::scene::ISceneNode *wall_Spawn_LeftBar2 = 0;
	irr::scene::ISceneNode *wall_Spawn_LeftBar3 = 0;
	irr::scene::ISceneNode *wall_Spawn_LeftBar4 = 0;

	irr::scene::ISceneNode *wall_Spawn_RightBar1 = 0;
	irr::scene::ISceneNode *wall_Spawn_RightBar2 = 0;
	irr::scene::ISceneNode *wall_Spawn_RightBar3 = 0;
	irr::scene::ISceneNode *wall_Spawn_RightBar4 = 0;

	irr::scene::ISceneNode *wall_MiddleLeft = 0;
	irr::scene::ISceneNode *wall_MiddleRight = 0;

	irr::scene::ISceneNode *wall_BackgroundLeft = 0;
	irr::scene::ISceneNode *wall_BackgroundRight = 0;

	irr::scene::ISceneNode *wall_CorridorLeft = 0;
	irr::scene::ISceneNode *wall_CorridorRight = 0;

	irr::scene::ISceneNode *wall_CorridorLeft2 = 0;
	irr::scene::ISceneNode *wall_CorridorRight2 = 0;

	irr::scene::ISceneNode *wall_CorridorHorizontal = 0;

	irr::scene::ISceneNode *wall_CorridorRoof1 = 0;
	irr::scene::ISceneNode *wall_CorridorRoof2 = 0;
	irr::scene::ISceneNode *wall_CorridorRoof3 = 0;

	irr::scene::ISceneNode *wall_ClosingUpLeft = 0;
	irr::scene::ISceneNode *wall_ClosingUpRight = 0;

	irr::scene::ISceneNode *wall_C_Left = 0;
	irr::scene::ISceneNode *wall_C_Left2 = 0;
	irr::scene::ISceneNode *wall_C_Left3= 0;

	irr::scene::ISceneNode *wall_C_Right = 0;
	irr::scene::ISceneNode *wall_C_Right2 = 0;
	irr::scene::ISceneNode *wall_C_Right3 = 0;

	wallLeft = addEntity(device_, mesh, "media/wall_ext1.jpg", irr::core::vector3df(-50, 35, 2400), irr::core::vector3df(100,50,315), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wallLeft));

	wallRight = addEntity(device_, mesh, "media/wall_ext1.jpg", irr::core::vector3df(4850, 35, 2400), irr::core::vector3df(100,50,315), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wallRight));

	wallUp = addEntity(device_, mesh, "media/wall_ext1.jpg", irr::core::vector3df(2400, 33, 4850), irr::core::vector3df(100,50,319), irr::core::vector3df(0, 90, 0), metaSelector);
	entities_.push_back(new Entity(*wallUp));

	wallDown = addEntity(device_, mesh, "media/wall_ext1.jpg", irr::core::vector3df(2400, -29, -20), irr::core::vector3df(100,50,319), irr::core::vector3df(0, 90, 0), metaSelector);
	// wall4 = addEntity(device_, mesh, "media/wall_ext1.jpg", irr::core::vector3df(2400, 35, -50), irr::core::vector3df(100,50,315), irr::core::vector3df(0, 90, 0), metaSelector);
	entities_.push_back(new Entity(*wallDown));

	wall_Spawn_Left = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(2110, 50, 485), irr::core::vector3df(50,15,53), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wall_Spawn_Left));

	wall_Spawn_Right = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(2610, 50, 485), irr::core::vector3df(50,15,53), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wall_Spawn_Right));


	wall_Spawn_Left2 = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(2110, 50, 1550), irr::core::vector3df(50,15,40), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wall_Spawn_Left2));

	wall_Spawn_Right2 = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(2610, 50, 1550), irr::core::vector3df(50,15,40), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wall_Spawn_Right2));


	wall_Spawn_Left2_2 = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(1300, 50, 1820), irr::core::vector3df(50,15,95), irr::core::vector3df(0, 90, 0), metaSelector);
	entities_.push_back(new Entity(*wall_Spawn_Left2_2));

	wall_Spawn_Right2_2 = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(3420, 50, 1820), irr::core::vector3df(50,15,95), irr::core::vector3df(0, 90, 0), metaSelector);
	entities_.push_back(new Entity(*wall_Spawn_Right2_2));


	wall_Spawn_LeftBar1 = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(1710, 50, 700), irr::core::vector3df(50,15,100), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wall_Spawn_LeftBar1));

	wall_Spawn_LeftBar2 = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(1350, 50, 1100), irr::core::vector3df(50,15,85), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wall_Spawn_LeftBar2));

	wall_Spawn_LeftBar3 = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(1000, 50, 700), irr::core::vector3df(50,15,100), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wall_Spawn_LeftBar3));

	wall_Spawn_LeftBar4 = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(589, 50, 1100), irr::core::vector3df(50,15,85), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wall_Spawn_LeftBar4));


	wall_Spawn_RightBar1 = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(3010, 50, 700), irr::core::vector3df(50,15,100), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wall_Spawn_RightBar1));

	wall_Spawn_RightBar2 = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(3370, 50, 1100), irr::core::vector3df(50,15,85), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wall_Spawn_RightBar2));

	wall_Spawn_RightBar3 = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(3720, 50, 700), irr::core::vector3df(50,15,100), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wall_Spawn_RightBar3));

	wall_Spawn_RightBar4 = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(4131, 50, 1100), irr::core::vector3df(50,15,85), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wall_Spawn_RightBar4));



	wall_MiddleLeft = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(1300, 50, 2320), irr::core::vector3df(50,15,95), irr::core::vector3df(0, 90, 0), metaSelector);
	entities_.push_back(new Entity(*wall_MiddleLeft));

	wall_MiddleRight = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(3420, 50, 2320), irr::core::vector3df(50,15,95), irr::core::vector3df(0, 90, 0), metaSelector);
	entities_.push_back(new Entity(*wall_MiddleRight));


	wall_BackgroundLeft = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(1300, 50, 4220), irr::core::vector3df(50,15,95), irr::core::vector3df(0, 90, 0), metaSelector);
	entities_.push_back(new Entity(*wall_BackgroundLeft));

	wall_BackgroundRight = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(3420, 50, 4220), irr::core::vector3df(50,15,95), irr::core::vector3df(0, 90, 0), metaSelector);
	entities_.push_back(new Entity(*wall_BackgroundRight));


	wall_CorridorLeft = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(2110, 50, 2590), irr::core::vector3df(50,15,40), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wall_CorridorLeft));

	wall_CorridorRight = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(2610, 50, 2590), irr::core::vector3df(50,15,40), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wall_CorridorRight));


	wall_CorridorLeft2 = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(2110, 50, 3750), irr::core::vector3df(50,15,65), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wall_CorridorLeft2));

	wall_CorridorRight2 = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(2610, 50, 3750), irr::core::vector3df(50,15,65), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wall_CorridorRight2));


	wall_CorridorRoof1 = addEntity(device_, mesh, "media/wall_ext2.jpg", irr::core::vector3df(2360, 100, 2330), irr::core::vector3df(55,1.5,30), irr::core::vector3df(0, 90, 0), metaSelector);
	entities_.push_back(new Entity(*wall_CorridorRoof1));

	wall_CorridorRoof2 = addEntity(device_, mesh, "media/wall_ext2.jpg", irr::core::vector3df(2360, 100, 2575), irr::core::vector3df(55,1.5,30), irr::core::vector3df(0, 90, 0), metaSelector);
	entities_.push_back(new Entity(*wall_CorridorRoof2));

	wall_CorridorRoof3 = addEntity(device_, mesh, "media/wall_ext2.jpg", irr::core::vector3df(2360, 100, 2850), irr::core::vector3df(55,1.5,30), irr::core::vector3df(0, 90, 0), metaSelector);
	entities_.push_back(new Entity(*wall_CorridorRoof3));


	wall_CorridorRoof1 = addEntity(device_, mesh, "media/wall_ext2.jpg", irr::core::vector3df(2360, 100, 3290), irr::core::vector3df(55,1.5,30), irr::core::vector3df(0, 90, 0), metaSelector);
	entities_.push_back(new Entity(*wall_CorridorRoof1));

	wall_CorridorRoof2 = addEntity(device_, mesh, "media/wall_ext2.jpg", irr::core::vector3df(2360, 100, 3593), irr::core::vector3df(55,1.5,30), irr::core::vector3df(0, 90, 0), metaSelector);
	entities_.push_back(new Entity(*wall_CorridorRoof2));

	wall_CorridorRoof2 = addEntity(device_, mesh, "media/wall_ext2.jpg", irr::core::vector3df(2360, 100, 3907), irr::core::vector3df(55,1.5,30), irr::core::vector3df(0, 90, 0), metaSelector);
	entities_.push_back(new Entity(*wall_CorridorRoof2));

	wall_CorridorRoof3 = addEntity(device_, mesh, "media/wall_ext2.jpg", irr::core::vector3df(2360, 100, 4210), irr::core::vector3df(55,1.5,30), irr::core::vector3df(0, 90, 0), metaSelector);
	entities_.push_back(new Entity(*wall_CorridorRoof3));


	wall_ClosingUpLeft = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(589, 50, 3300), irr::core::vector3df(50,15,120), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wall_ClosingUpLeft));

	wall_ClosingUpRight = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(4131, 50, 3300), irr::core::vector3df(50,15,120), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wall_ClosingUpRight));


	wall_C_Left = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(1660, 50, 3160), irr::core::vector3df(50,15,70), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wall_C_Left));

	wall_C_Left2 = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(1360, 50, 3670), irr::core::vector3df(50,15,35), irr::core::vector3df(0, 90, 0), metaSelector);
	entities_.push_back(new Entity(*wall_C_Left2));

	wall_C_Left3 = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(1360, 50, 2650), irr::core::vector3df(50,15,35), irr::core::vector3df(0, 90, 0), metaSelector);
	entities_.push_back(new Entity(*wall_C_Left3));


	wall_C_Right = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(3160, 50, 3160), irr::core::vector3df(50,15,70), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new Entity(*wall_C_Right));

	wall_C_Right2 = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(3420, 50, 3670), irr::core::vector3df(50,15,35), irr::core::vector3df(0, 90, 0), metaSelector);
	entities_.push_back(new Entity(*wall_C_Right2));

	wall_C_Right3 = addEntity(device_, mesh, "media/wall_in.jpg", irr::core::vector3df(3420, 50, 2650), irr::core::vector3df(50,15,35), irr::core::vector3df(0, 90, 0), metaSelector);
	entities_.push_back(new Entity(*wall_C_Right3));

	smgr->getMeshManipulator()->makePlanarTextureMapping(mesh, 1.f);


	// Torches
	mesh = smgr->getMesh("media/FireTorchOBJ.OBJ");
	addEntity(device_, mesh, "media/Wagen_1.jpg", irr::core::vector3df(35, 35, 300), irr::core::vector3df(1.5,1.5,1.5), irr::core::vector3df(35, 90, 0), metaSelector);
	mesh = smgr->getMesh("media/FireTorchOBJ.OBJ");
	addEntity(device_, mesh, "media/Wagen_1.jpg", irr::core::vector3df(35, 35, 900), irr::core::vector3df(1.5,1.5,1.5), irr::core::vector3df(35, 90, 0), metaSelector);
	mesh = smgr->getMesh("media/FireTorchOBJ.OBJ");
	addEntity(device_, mesh, "media/Wagen_1.jpg", irr::core::vector3df(35, 35, 1500), irr::core::vector3df(1.5,1.5,1.5), irr::core::vector3df(35, 90, 0), metaSelector);
	mesh = smgr->getMesh("media/FireTorchOBJ.OBJ");
	addEntity(device_, mesh, "media/Wagen_1.jpg", irr::core::vector3df(35, 35, 2100), irr::core::vector3df(1.5,1.5,1.5), irr::core::vector3df(35, 90, 0), metaSelector);
	mesh = smgr->getMesh("media/FireTorchOBJ.OBJ");
	addEntity(device_, mesh, "media/Wagen_1.jpg", irr::core::vector3df(35, 35, 2600), irr::core::vector3df(1.5,1.5,1.5), irr::core::vector3df(35, 90, 0), metaSelector);
	mesh = smgr->getMesh("media/FireTorchOBJ.OBJ");
	addEntity(device_, mesh, "media/Wagen_1.jpg", irr::core::vector3df(35, 35, 3200), irr::core::vector3df(1.5,1.5,1.5), irr::core::vector3df(35, 90, 0), metaSelector);
	mesh = smgr->getMesh("media/FireTorchOBJ.OBJ");
	addEntity(device_, mesh, "media/Wagen_1.jpg", irr::core::vector3df(35, 35, 3800), irr::core::vector3df(1.5,1.5,1.5), irr::core::vector3df(35, 90, 0), metaSelector);
	mesh = smgr->getMesh("media/FireTorchOBJ.OBJ");
	addEntity(device_, mesh, "media/Wagen_1.jpg", irr::core::vector3df(35, 35, 4400), irr::core::vector3df(1.5,1.5,1.5), irr::core::vector3df(35, 90, 0), metaSelector);

	mesh = smgr->getMesh("media/FireTorchOBJ.OBJ");
	addEntity(device_, mesh, "media/Wagen_1.jpg", irr::core::vector3df(4760, 35, 500), irr::core::vector3df(1.5,1.5,1.5), irr::core::vector3df(35, -90, 0), metaSelector);
	mesh = smgr->getMesh("media/FireTorchOBJ.OBJ");
	addEntity(device_, mesh, "media/Wagen_1.jpg", irr::core::vector3df(4760, 35, 1100), irr::core::vector3df(1.5,1.5,1.5), irr::core::vector3df(35, -90, 0), metaSelector);
	mesh = smgr->getMesh("media/FireTorchOBJ.OBJ");
	addEntity(device_, mesh, "media/Wagen_1.jpg", irr::core::vector3df(4760, 35, 1700), irr::core::vector3df(1.5,1.5,1.5), irr::core::vector3df(35, -90, 0), metaSelector);
	mesh = smgr->getMesh("media/FireTorchOBJ.OBJ");
	addEntity(device_, mesh, "media/Wagen_1.jpg", irr::core::vector3df(4760, 35, 2300), irr::core::vector3df(1.5,1.5,1.5), irr::core::vector3df(35, -90, 0), metaSelector);
	mesh = smgr->getMesh("media/FireTorchOBJ.OBJ");
	addEntity(device_, mesh, "media/Wagen_1.jpg", irr::core::vector3df(4760, 35, 2900), irr::core::vector3df(1.5,1.5,1.5), irr::core::vector3df(35, -90, 0), metaSelector);
	mesh = smgr->getMesh("media/FireTorchOBJ.OBJ");
	addEntity(device_, mesh, "media/Wagen_1.jpg", irr::core::vector3df(4760, 35, 3500), irr::core::vector3df(1.5,1.5,1.5), irr::core::vector3df(35, -90, 0), metaSelector);
	mesh = smgr->getMesh("media/FireTorchOBJ.OBJ");
	addEntity(device_, mesh, "media/Wagen_1.jpg", irr::core::vector3df(4760, 35, 4100), irr::core::vector3df(1.5,1.5,1.5), irr::core::vector3df(35, -90, 0), metaSelector);
	// mesh = smgr->getMesh("media/Water Well.obj");
	// addEntity(device_, mesh, "media/Wagen_1.jpg", irr::core::vector3df(2360, 0, 1100), irr::core::vector3df(30,30,30), irr::core::vector3df(0, 180, 0), metaSelector);

	// Dragons
	mesh = smgr->getMesh("media/Drachen_1.0_obj.obj");
	addEntity(device_, mesh, "media/textures/dragon_S.jpg", irr::core::vector3df(2110, 130, 1820), irr::core::vector3df(1.5,1.5,1.5), irr::core::vector3df(0, 45, 0), metaSelector);
	mesh = smgr->getMesh("media/Drachen_1.0_obj.obj");
	addEntity(device_, mesh, "media/textures/dragon_S.jpg", irr::core::vector3df(2610, 130, 1820), irr::core::vector3df(1.5,1.5,1.5), irr::core::vector3df(0, -45, 0), metaSelector);
	// Wagen
	irr::scene::IMeshSceneNode* node = 0;
	mesh = smgr->getMesh("media/wagen1_Lp_End.3ds");
	node = addEntity(device_, mesh, "media/Wagen_1.jpg", irr::core::vector3df(2090, 0, 1000), irr::core::vector3df(1.5,1.5,1.5), irr::core::vector3df(0, 0, 0), metaSelector);
	entities_.push_back(new DestructibleObject(*node));
	node = addEntity(device_, mesh, "media/Wagen_1.jpg", irr::core::vector3df(2630, 0, 1100), irr::core::vector3df(1.5,1.5,1.5), irr::core::vector3df(0, 180, 0), metaSelector);
	entities_.push_back(new DestructibleObject(*node));


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// add light 1 (more green)
	irr::scene::ILightSceneNode* lightleft1 =
	smgr->addLightSceneNode(0, irr::core::vector3df(105,132,300),
		irr::video::SColorf(0.5f, 1.0f, 0.5f, 0.0f), 800.0f);

	lightleft1->setDebugDataVisible ( irr::scene::EDS_BBOX );

	// attach billboard to the light
	irr::scene::IBillboardSceneNode* bill =
	smgr->addBillboardSceneNode(lightleft1, irr::core::dimension2d<irr::f32>(60, 60));

	bill->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	bill->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	bill->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
	bill->setMaterialTexture(0, driver->getTexture("media/particlegreen.jpg"));

	// add light 2 (red)
	irr::scene::ISceneNode* lightleft1_1 =
	smgr->addLightSceneNode(0, irr::core::vector3df(105,132,300),
		irr::video::SColorf(1.0f, 0.2f, 0.2f, 0.0f), 800.0f);

	// attach billboard to light
	bill = smgr->addBillboardSceneNode(lightleft1_1, irr::core::dimension2d<irr::f32>(120, 120));
	bill->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	bill->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	bill->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
	bill->setMaterialTexture(0, driver->getTexture("media/particlered.bmp"));

	// add particle system
	irr::scene::IParticleSystemSceneNode* ps =
	smgr->addParticleSystemSceneNode(false, lightleft1_1);

	// create and set emitter
	irr::scene::IParticleEmitter* em = ps->createBoxEmitter(
		irr::core::aabbox3d<irr::f32>(-3,0,-3,3,1,3),
		irr::core::vector3df(0.0f,0.03f,0.0f),
		80,100,
		irr::video::SColor(10,255,255,255), irr::video::SColor(10,255,255,255),
		400,1100);
	em->setMinStartSize(irr::core::dimension2d<irr::f32>(30.0f, 40.0f));
	em->setMaxStartSize(irr::core::dimension2d<irr::f32>(30.0f, 40.0f));

	ps->setEmitter(em);
	em->drop();

	// create and set affector
	irr::scene::IParticleAffector* paf = ps->createFadeOutParticleAffector();
	ps->addAffector(paf);
	paf->drop();

	// adjust some material settings
	ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	ps->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	ps->setMaterialTexture(0, driver->getTexture("media/fireball.bmp"));
	ps->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	irr::scene::IAnimatedMeshSceneNode* node2 = 0;

	// speed powerup
	node2 = smgr->addAnimatedMeshSceneNode(smgr->getMesh("media/3d-model.obj"), 0, 21);
	node2->setMaterialTexture(0, driver->getTexture("media/wood-normal.jpg"));
	node2->setPosition(irr::core::vector3df(1890, 1, 1000));
	node2->setScale(irr::core::vector3df(0.07f, 0.07f, 0.07f));
	node2->setRotation(irr::core::vector3df(0, 180, 0));
	node2->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	SpeedPowerUp *spu = new SpeedPowerUp(*node2);
	powerups_.push_back(spu);

	node2 = smgr->addAnimatedMeshSceneNode(smgr->getMesh("media/3d-model.obj"), 0, 21);
	node2->setMaterialTexture(0, driver->getTexture("media/wood-normal.jpg"));
	node2->setPosition(irr::core::vector3df(2830, 1, 1000));
	node2->setScale(irr::core::vector3df(0.07f, 0.07f, 0.07f));
	node2->setRotation(irr::core::vector3df(0, 180, 0));
	node2->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	SpeedPowerUp *spu2 = new SpeedPowerUp(*node2);
	powerups_.push_back(spu2);
	// life powerup
	node2 = smgr->addAnimatedMeshSceneNode(smgr->getMesh("media/Heart.obj"), 0, 21);
	node2->setMaterialTexture(0, driver->getTexture("media/heart.jpg"));
	node2->setPosition(irr::core::vector3df(1260, 20, 3000));
	node2->setScale(irr::core::vector3df(0.8f, 0.8f, 0.8f));
	node2->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	LifePowerUp *lpu = new LifePowerUp(*node2);
	powerups_.push_back(lpu);

	node2 = smgr->addAnimatedMeshSceneNode(smgr->getMesh("media/Heart.obj"), 0, 21);
	node2->setMaterialTexture(0, driver->getTexture("media/heart.jpg"));
	node2->setPosition(irr::core::vector3df(3520, 20, 3000));
	node2->setScale(irr::core::vector3df(0.8f, 0.8f, 0.8f));
	node2->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	LifePowerUp *lpu2 = new LifePowerUp(*node2);
	powerups_.push_back(lpu2);
	// atkspeed powerup
	node2 = smgr->addAnimatedMeshSceneNode(smgr->getMesh("media/sword.obj"), 0, 21);
	node2->setMaterialTexture(0, driver->getTexture("media/swordCarolingianTypeX_diff.jpg"));
	node2->setScale(irr::core::vector3df(20.0f, 7.0f, 20.0f));
	node2->setPosition(irr::core::vector3df(2360, 1, 2060));
	node2->setRotation(irr::core::vector3df(0, 180, 0));
	node2->setAnimationSpeed(10.0f);
	node2->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	AtkSpeedPowerUp *aspu = new AtkSpeedPowerUp(*node2);
	powerups_.push_back(aspu);
}

void Level1State::init() {
	irr::video::IVideoDriver *driver = device_.getVideoDriver();
	irr::scene::ISceneManager *smgr = device_.getSceneManager();
	device_.setWindowCaption(L"Gauntlet by Couchard & Co");
	device_.getCursorControl()->setVisible(false);
	// Meta selector & map
	irr::scene::IMetaTriangleSelector* metaSelector = smgr->createMetaTriangleSelector();
	genMap(metaSelector, powerups_);
	// adding a characters
	irr::scene::ITriangleSelector* selector = 0;
	irr::scene::IAnimatedMeshSceneNode* node = 0;
	int x = 2362;
	int z = 300;
	for (int i = 0; i < players_nb_; i++, x+=50, z+=50) {
		node = addPlayer(device_, smgr->getMesh("media/dwarf.x"), irr::core::vector3df(x,1,z), irr::core::vector3df(1), irr::core::vector3df(0), metaSelector);
		// player camera and HUD
		cameras_[i] = smgr->addCameraSceneNode(0, irr::core::vector3df(x, 400, z - 300), node->getPosition());
		PlayerCharacter *player;
		if (i == 0)
			player = new PlayerCharacter(*node, *cameras_[i], *proj_mngr_, *AI_mngr_, 1);
		else if (i == 1)
			player = new PlayerCharacter(*node, *cameras_[i], *proj_mngr_, *AI_mngr_, 2);
		else
			player = new PlayerCharacter(*node, *cameras_[i], *proj_mngr_, *AI_mngr_, 3);
		huds_[i]->GetLifeBarModule().AttachCharacter(player);
		entities_.push_back(player);
	}
	// adding a mob
	irr::scene::IAnimatedMesh *amesh = smgr->getMesh("media/monster-animated-character.b3d");
	// node = addMob(device_, amesh, irr::core::vector3df(200, 1, 900), irr::core::vector3df(3.0f, 1.5f, 3.0f), irr::core::vector3df(0,180,0), metaSelector, 21, 150, 190, 10.0f);
	// entities_.push_back(new NonPlayerCharacter(*node, *proj_mngr_, *AI_mngr_, 400));

	// MOBS SORTIE DU SPAWN
	node = addMob(device_, amesh, irr::core::vector3df(1960, 1, 2100), irr::core::vector3df(3.0f, 1.5f, 3.0f), irr::core::vector3df(0,0,0), metaSelector, 21, 150, 190, 10.0f);
	entities_.push_back(new NonPlayerCharacter(*node, *proj_mngr_, *AI_mngr_, 400));

	node = addMob(device_, amesh, irr::core::vector3df(2860, 1, 2100), irr::core::vector3df(3.0f, 1.5f, 3.0f), irr::core::vector3df(0,180,0), metaSelector, 21, 150, 190, 10.0f);
	entities_.push_back(new NonPlayerCharacter(*node, *proj_mngr_, *AI_mngr_, 400));

	// MOBS LABYRINTHE
	node = addMob(device_, amesh, irr::core::vector3df(3340, 1, 800), irr::core::vector3df(3.0f, 1.5f, 3.0f), irr::core::vector3df(0,180,0), metaSelector, 21, 150, 190, 10.0f);
	entities_.push_back(new NonPlayerCharacter(*node, *proj_mngr_, *AI_mngr_, 400));

	node = addMob(device_, amesh, irr::core::vector3df(1480, 1, 800), irr::core::vector3df(3.0f, 1.5f, 3.0f), irr::core::vector3df(0,180,0), metaSelector, 21, 150, 190, 10.0f);
	entities_.push_back(new NonPlayerCharacter(*node, *proj_mngr_, *AI_mngr_, 400));

	//MOBS C_LEFT
	node = addMob(device_, amesh, irr::core::vector3df(1480, 1, 3200), irr::core::vector3df(3.0f, 1.5f, 3.0f), irr::core::vector3df(0,180,0), metaSelector, 21, 150, 190, 10.0f);
	entities_.push_back(new NonPlayerCharacter(*node, *proj_mngr_, *AI_mngr_, 400));
	node = addMob(device_, amesh, irr::core::vector3df(1360, 1, 3000), irr::core::vector3df(3.0f, 1.5f, 3.0f), irr::core::vector3df(0,180,0), metaSelector, 21, 150, 190, 10.0f);
	entities_.push_back(new NonPlayerCharacter(*node, *proj_mngr_, *AI_mngr_, 400));
	node = addMob(device_, amesh, irr::core::vector3df(1220, 1, 2800), irr::core::vector3df(3.0f, 1.5f, 3.0f), irr::core::vector3df(0,180,0), metaSelector, 21, 150, 190, 10.0f);
	entities_.push_back(new NonPlayerCharacter(*node, *proj_mngr_, *AI_mngr_, 400));

	//MOBS C_RIGHT
	node = addMob(device_, amesh, irr::core::vector3df(3560, 1, 3200), irr::core::vector3df(3.0f, 1.5f, 3.0f), irr::core::vector3df(0,180,0), metaSelector, 21, 150, 190, 10.0f);
	entities_.push_back(new NonPlayerCharacter(*node, *proj_mngr_, *AI_mngr_, 400));
	node = addMob(device_, amesh, irr::core::vector3df(3420, 1, 3000), irr::core::vector3df(3.0f, 1.5f, 3.0f), irr::core::vector3df(0,180,0), metaSelector, 21, 150, 190, 10.0f);
	entities_.push_back(new NonPlayerCharacter(*node, *proj_mngr_, *AI_mngr_, 400));
	node = addMob(device_, amesh, irr::core::vector3df(3300, 1, 2800), irr::core::vector3df(3.0f, 1.5f, 3.0f), irr::core::vector3df(0,180,0), metaSelector, 21, 150, 190, 10.0f);
	entities_.push_back(new NonPlayerCharacter(*node, *proj_mngr_, *AI_mngr_, 400));

	irr::scene::ISceneNodeAnimator *anim = 0;
	// collisions
	anim = smgr->createCollisionResponseAnimator(metaSelector, node, irr::core::vector3df(25,1,25), irr::core::vector3df(0,-10,0), irr::core::vector3df(0,0,0));
	node->addAnimator(anim);
	anim->drop();
	entities_.push_back(new NonPlayerCharacter(*node, *proj_mngr_, *AI_mngr_, 400));
	// // speed powerup
	// node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("media/3d-model.obj"), 0, 21);
	// node->setPosition(irr::core::vector3df(1890, 1, 1000));
	// node->setScale(irr::core::vector3df(0.07f, 0.07f, 0.07f));
	// node->setRotation(irr::core::vector3df(0, 180, 0));
	// node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	// SpeedPowerUp *spu = new SpeedPowerUp(*node);
	// powerups_.push_back(spu);

	// node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("media/3d-model.obj"), 0, 21);
	// node->setPosition(irr::core::vector3df(2830, 1, 1000));
	// node->setScale(irr::core::vector3df(0.07f, 0.07f, 0.07f));
	// node->setRotation(irr::core::vector3df(0, 180, 0));
	// node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	// SpeedPowerUp *spu2 = new SpeedPowerUp(*node);
	// powerups_.push_back(spu2);
	// // life powerup
	// node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("media/Heart.obj"), 0, 21);
	// node->setMaterialTexture(0, driver->getTexture("media/heart.jpg"));
	// node->setPosition(irr::core::vector3df(1360, 20, 3000));
	// node->setScale(irr::core::vector3df(0.8f, 0.8f, 0.8f));
	// node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	// LifePowerUp *lpu = new LifePowerUp(*node);
	// powerups_.push_back(lpu);

	// node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("media/Heart.obj"), 0, 21);
	// node->setMaterialTexture(0, driver->getTexture("media/heart.jpg"));
	// node->setPosition(irr::core::vector3df(3420, 20, 3000));
	// node->setScale(irr::core::vector3df(0.8f, 0.8f, 0.8f));
	// node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	// LifePowerUp *lpu2 = new LifePowerUp(*node);
	// powerups_.push_back(lpu2);
	// // atkspeed powerup
	// node = smgr->addAnimatedMeshSceneNode(smgr->getMesh("media/sword.obj"), 0, 21);
	// node->setMaterialTexture(0, driver->getTexture("media/swordCarolingianTypeX_diff.jpg"));
	// node->setScale(irr::core::vector3df(20.0f, 7.0f, 20.0f));
	// node->setPosition(irr::core::vector3df(2360, 1, 2060));
	// node->setRotation(irr::core::vector3df(0, 180, 0));
	// node->setAnimationSpeed(10.0f);
	// node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	// AtkSpeedPowerUp *aspu = new AtkSpeedPowerUp(*node);
	// powerups_.push_back(aspu);
}

void Level1State::initLoad(std::vector<std::string> tabinfo) {
	irr::video::IVideoDriver *driver = device_.getVideoDriver();
	irr::scene::ISceneManager *smgr = device_.getSceneManager();
	device_.setWindowCaption(L"Gauntlet by Couchard & Co");
	device_.getCursorControl()->setVisible(false);
	// Meta selector & map
	irr::scene::IMetaTriangleSelector* metaSelector = smgr->createMetaTriangleSelector();
	genMap(metaSelector, powerups_);
	// adding a characters
	irr::scene::ITriangleSelector* selector = 0;
	irr::scene::IAnimatedMeshSceneNode* node = 0;
	int x = 2;
	for (int i = 0; i < players_nb_; i++, x+=7) {
		node = addPlayer(device_, smgr->getMesh("media/dwarf.x"), irr::core::vector3df(atoi(tabinfo[x].c_str()),1, atoi(tabinfo[x + 2].c_str())), irr::core::vector3df(1), irr::core::vector3df(atoi(tabinfo[x + 3].c_str()), atoi(tabinfo[x + 4].c_str()), atoi(tabinfo[x + 5].c_str())), metaSelector);
		// player camera and HUD
		cameras_[i] = smgr->addCameraSceneNode(0, irr::core::vector3df(atoi(tabinfo[x].c_str()), 400, atoi(tabinfo[x + 2].c_str()) - 300), node->getPosition());
		PlayerCharacter *player;
		if (i == 0)
			player = new PlayerCharacter(*node, *cameras_[i], *proj_mngr_, *AI_mngr_, 1);
		else if (i == 1)
			player = new PlayerCharacter(*node, *cameras_[i], *proj_mngr_, *AI_mngr_, 2);
		else
			player = new PlayerCharacter(*node, *cameras_[i], *proj_mngr_, *AI_mngr_, 3);

		huds_[i]->GetLifeBarModule().AttachCharacter(player);
		player->SetLife(atoi(tabinfo[x - 1].c_str()));
		entities_.push_back(player);
	}

	// adding a mob
	irr::scene::IAnimatedMesh *amesh = smgr->getMesh("media/monster-animated-character.b3d");
	for (int i = 0; x < tabinfo.size(); x+=7)
	{
		if (atoi(tabinfo[x - 1].c_str()) > 0)
		{
			node = addMob(device_, amesh, irr::core::vector3df(atoi(tabinfo[x].c_str()), 1, atoi(tabinfo[x + 2].c_str())), irr::core::vector3df(3.0f, 3.0f, 3.0f), irr::core::vector3df(atoi(tabinfo[x + 3].c_str()),atoi(tabinfo[x + 4].c_str()),atoi(tabinfo[x + 5].c_str())), metaSelector, 21, 150, 190, 10.0f);
			NonPlayerCharacter *mob = new NonPlayerCharacter(*node, *proj_mngr_, *AI_mngr_, 400);
			entities_.push_back(mob);
		}
	}
}

void Level1State::drop() {
	irr::scene::ISceneManager *smgr = device_.getSceneManager();

	smgr->clear();
	for (std::list<Entity *>::iterator it = entities_.begin(); it != entities_.end(); it++) {
		delete *it;
	}
}

void Level1State::Events(EventReceiver *receiver) {
	irr::u16 players = 0;
	irr::u16 mobs = 0;
	for (std::list<Entity *>::iterator ent = entities_.begin(); ent != entities_.end(); ent++) {
		if (PlayerCharacter *c = dynamic_cast<PlayerCharacter *>(*ent))
			players++;
		if (NonPlayerCharacter *c = dynamic_cast<NonPlayerCharacter *>(*ent))
			mobs++;
	}
	if (!players) {
		GameOverState *gos = new GameOverState(device_);
		StateManager::Instance()->Replace(gos);
	} else if (!mobs) {
		WonGameState *wgs = new WonGameState(device_);
		StateManager::Instance()->Replace(wgs);
	} else {
		event_handler_->HandleEvent(receiver, device_, entities_);
	}
}

void Level1State::Update() {
	irr::u16 players = 0;
	irr::u16 mobs = 0;
	for (std::list<Entity *>::iterator ent = entities_.begin(); ent != entities_.end(); ent++) {
		if (PlayerCharacter *c = dynamic_cast<PlayerCharacter *>(*ent))
			players++;
		if (NonPlayerCharacter *c = dynamic_cast<NonPlayerCharacter *>(*ent))
			mobs++;
	}
	if (!players) {
		GameOverState *gos = new GameOverState(device_);
		StateManager::Instance()->Replace(gos);
	} else if (!mobs) {
		WonGameState *wgs = new WonGameState(device_);
		StateManager::Instance()->Replace(wgs);
	} else {
		update_handler_->HandleUpdate(entities_);
	}
	for (std::list<PowerUp *>::iterator pu = powerups_.begin(); pu != powerups_.end(); pu++) {
		for (std::list<Entity *>::iterator ent = entities_.begin(); ent != entities_.end(); ent++) {
			irr::f32 dist = (*pu)->GetPos().getDistanceFrom((*ent)->GetPos());
			if (Character *c = dynamic_cast<Character *>(*ent)) {
				if (dist < 30 && c) {
					(*pu)->Buff(*c);
					(*pu)->Remove();
					pu = powerups_.erase(pu);
					return;
				}
			}
		}
	}
}

void Level1State::Render() {
	irr::u16 players = 0;
	irr::u16 mobs = 0;
	for (std::list<Entity *>::iterator ent = entities_.begin(); ent != entities_.end(); ent++) {
		if (PlayerCharacter *c = dynamic_cast<PlayerCharacter *>(*ent)) {
			if (c->GetState() == Character::DEAD) {
				huds_[c->GetPlayerID() - 1]->GetLifeBarModule().DetachCharacter();
				ent = entities_.erase(ent);
				c->Destroy();
				delete c;
				return;
			}
		}
		if (PlayerCharacter *c = dynamic_cast<PlayerCharacter *>(*ent))
			players++;
		if (NonPlayerCharacter *c = dynamic_cast<NonPlayerCharacter *>(*ent))
			mobs++;
	}
	if (!players) {
		GameOverState *gos = new GameOverState(device_);
		StateManager::Instance()->Replace(gos);
	} else if (!mobs) {
		WonGameState *wgs = new WonGameState(device_);
		StateManager::Instance()->Replace(wgs);
	} else {
		render_handler_->HandleRender(device_, huds_, players_nb_, cameras_);
	}
}
