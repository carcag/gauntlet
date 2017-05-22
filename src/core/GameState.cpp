#include "GameState.hpp"
#include "PlayerCharacter.hpp"
#include "HUD.hpp"

GameState::GameState(irr::IrrlichtDevice& device, irr::u16 players_nb = 1) : IState(device), players_nb_(players_nb) {
}

GameState::~GameState() {
}

irr::scene::IMeshSceneNode *GameState::addEntity(irr::IrrlichtDevice& device, irr::scene::IMesh *mesh, const irr::io::path& texture_path, irr::core::vector3df pos, irr::core::vector3df scale, irr::core::vector3df rotation, irr::scene::IMetaTriangleSelector *metaSelector) {
	irr::scene::IMeshSceneNode *scene_node = 0;
	irr::scene::ITriangleSelector *selector = 0;
	irr::video::IVideoDriver *driver = device.getVideoDriver();
	irr::scene::ISceneManager *smgr = device.getSceneManager();

	scene_node = smgr->addMeshSceneNode(mesh);
	scene_node->setPosition(pos);
	scene_node->setScale(scale);
	scene_node->setRotation(rotation);
	scene_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	scene_node->setMaterialType(irr::video::EMT_DETAIL_MAP);
	scene_node->setMaterialTexture(0, driver->getTexture(texture_path));
	selector = smgr->createTriangleSelectorFromBoundingBox(scene_node);
	scene_node->setTriangleSelector(selector);
	metaSelector->addTriangleSelector(selector);
	selector->drop();
	return (scene_node);
};

irr::scene::IAnimatedMeshSceneNode *GameState::addMob(irr::IrrlichtDevice& device, irr::scene::IAnimatedMesh *mesh, irr::core::vector3df pos, irr::core::vector3df scale, irr::core::vector3df rotation, irr::scene::IMetaTriangleSelector *metaSelector, irr::s32 id, irr::s32 begin, irr::s32 end, irr::f32 speed) {
	irr::scene::IAnimatedMeshSceneNode *scene_node = 0;
	irr::scene::ITriangleSelector *selector = 0;
	irr::scene::ISceneManager *smgr = device.getSceneManager();

	scene_node = smgr->addAnimatedMeshSceneNode(mesh, 0, id);
	scene_node->setPosition(pos);
	scene_node->setScale(scale);
	scene_node->setRotation(rotation);
	scene_node->setFrameLoop(begin, end);
	scene_node->setAnimationSpeed(speed);
	scene_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = smgr->createCollisionResponseAnimator(metaSelector, scene_node, irr::core::vector3df(25,1,25), irr::core::vector3df(0,-10,0), irr::core::vector3df(0,0,0));
	scene_node->addAnimator(anim);
	anim->drop();
	selector = smgr->createTriangleSelector(scene_node);
	scene_node->setTriangleSelector(selector);
	selector->drop();
	return (scene_node);
}

irr::scene::IAnimatedMeshSceneNode *GameState::addPlayer(irr::IrrlichtDevice& device, irr::scene::IAnimatedMesh *mesh, irr::core::vector3df pos, irr::core::vector3df scale, irr::core::vector3df rotation, irr::scene::IMetaTriangleSelector *metaSelector) {
	irr::scene::ITriangleSelector* selector = 0;
	irr::scene::IAnimatedMeshSceneNode* scene_node = 0;
	irr::scene::ISceneManager *smgr = device.getSceneManager();

	scene_node = smgr->addAnimatedMeshSceneNode(mesh, 0, 42);
	scene_node->setPosition(pos);
	scene_node->setScale(scale);
	scene_node->setRotation(rotation);
	scene_node->setAnimationSpeed(90.0f);
	scene_node->setJointMode(irr::scene::EJUOR_CONTROL);
	scene_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	selector = smgr->createTriangleSelector(scene_node);
	scene_node->setTriangleSelector(selector);
	selector->drop();
	irr::scene::ISceneNodeAnimator *anim = smgr->createCollisionResponseAnimator(metaSelector, scene_node, irr::core::vector3df(25,1,25), irr::core::vector3df(0,-10,0), irr::core::vector3df(0,0,0));
	scene_node->addAnimator(anim);
	anim->drop();
	return (scene_node);
}
