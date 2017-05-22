#include <iostream>
#include "ProjectileManager.hpp"
#include "PlayerCharacter.hpp"
#include "DestructibleObject.hpp"
#include "NonPlayerCharacter.hpp"

ProjectileManager::ProjectileManager(irr::IrrlichtDevice& device, std::list<Entity *>& entities) : device_(device), entities_(entities) {
}

ProjectileManager::~ProjectileManager() {
}

void ProjectileManager::FireProjectile(Character& c, irr::core::line3df line) {
	irr::scene::ISceneManager *smgr = device_.getSceneManager();

	irr::core::vector3df collision_point;
	irr::core::triangle3df collision_triangle;
	irr::scene::ISceneNode *hit_node;
	for (std::list<Entity *>::iterator ent = entities_.begin(); ent != entities_.end(); ent++) {
		if (smgr->getSceneCollisionManager()->getCollisionPoint(line,(*ent)->GetTriangleSelector(), collision_point, collision_triangle, hit_node) && (*hit_node).getID() != c.GetID()) {
			if (NonPlayerCharacter *target = dynamic_cast<NonPlayerCharacter *>(*ent)) {
				target->TakeDamage(c.GetRangeDamage());
				if (!c.GetPierce() && target->GetState() == Character::ALIVE)
					line.end = hit_node->getPosition();
				else if (target->GetState() != Character::ALIVE) {
					if (PlayerCharacter *player = dynamic_cast<PlayerCharacter *>(&c))
						player->AddScore(target->GetPointsValue());
				}
			} else if (DestructibleObject *target = dynamic_cast<DestructibleObject *>(*ent)) {
				line.end = hit_node->getPosition();
				target->TakeDamage(c.GetRangeDamage());
			} else if (PlayerCharacter *target = dynamic_cast<PlayerCharacter *>(*ent)) {
				line.end = hit_node->getPosition();
				target->TakeDamage(c.GetRangeDamage());
			} else{
				line.end = collision_point;
			}
		}
	}
	irr::scene::ISceneNode* fire = 0;
	fire = smgr->addBillboardSceneNode(0 , irr::core::dimension2d<irr::f32>(35,35), line.start);
	fire->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	fire->setMaterialTexture(0, device_.getVideoDriver()->getTexture("media/fire.bmp"));
	fire->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	fire->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
	irr::f32 length = (irr::f32)(line.end - line.start).getLength();
	const irr::f32 speed = 1.0f;
	irr::u32 time = (irr::u32)(length / speed);
	irr::scene::ISceneNodeAnimator* anim = 0;
	anim = smgr->createFlyStraightAnimator(line.start, line.end, time);
	fire->addAnimator(anim);
	anim->drop();
	anim = smgr->createDeleteAnimator(time);
	fire->addAnimator(anim);
	anim->drop();
}
