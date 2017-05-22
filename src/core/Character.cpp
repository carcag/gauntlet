#include <iostream>
#include "Character.hpp"
#include "PlayerCharacter.hpp"

Character::Character(irr::scene::ISceneNode& node, ProjectileManager& proj_mngr, AI& AI_mngr) : Entity(node), proj_mngr_(proj_mngr), AI_mngr_(AI_mngr) {
	speed_ = 5.f;
	life_ = 4;
	range_ = 1000;
	proj_dmg_ = 1;
	proj_pierce_ = false;
	range_atk_speed_ = .25;
	state_ = ALIVE;
	AI_EntityType_ = OBJECT;
}

Character::~Character() {
}

void Character::die() {
	if (irr::scene::IAnimatedMeshSceneNode *animatedMesh = static_cast<irr::scene::IAnimatedMeshSceneNode *>(&node_)) {
		state_ = DYING;
		animatedMesh->setFrameLoop(500, 550);
		animatedMesh->setAnimationSpeed(20.0f);
		death_time_ = std::chrono::steady_clock::now();
	}
	std::cout << GetID() << " died()" << std::endl;
}

const irr::u32& Character::GetLife() const {
	return (life_);
}

const bool& Character::GetPierce() const {
	return (proj_pierce_);
}

const irr::u32& Character::GetRangeDamage() const {
	return (proj_dmg_);
}

const irr::f32& Character::GetAtkSpeed() const {
	return (range_atk_speed_);
}

const Character::State& Character::GetState() const {
	return (state_);
}

void Character::SetSpeed(irr::f32 speed) {
	speed_ = speed;
}

void Character::SetLife(irr::u32 life) {
	life_ = std::min(irr::u32(4), life);
}

void Character::SetAtkSpeed(irr::f32 atkspeed) {
	range_atk_speed_ = atkspeed;
}

void Character::TakeDamage(irr::u32 dmg) {
	if (life_ == 0)
		return;
	life_ = std::max(irr::u32(0), life_ - dmg);
	if (life_ == 0) {
		if (PlayerCharacter *pc = dynamic_cast<PlayerCharacter *>(this)) {
			pc->die();
		} else {
			die();
		}
	}
}

void Character::MoveUp() {
	node_.setRotation(irr::core::vector3df(0, 180, 0));
	irr::core::vector3df pos = node_.getPosition();
	pos.Z += speed_;
	node_.setPosition(pos);
	if (irr::scene::IAnimatedMeshSceneNode *animatedMesh = static_cast<irr::scene::IAnimatedMeshSceneNode *>(&node_))
		animatedMesh->animateJoints();
}

void Character::MoveDown() {
	node_.setRotation(irr::core::vector3df(0, 0, 0));
	irr::core::vector3df pos = node_.getPosition();
	pos.Z -= speed_;
	node_.setPosition(pos);
	if (irr::scene::IAnimatedMeshSceneNode *animatedMesh = static_cast<irr::scene::IAnimatedMeshSceneNode *>(&node_))
		animatedMesh->animateJoints();
}

void Character::MoveLeft() {
	node_.setRotation(irr::core::vector3df(0, 90, 0));
	irr::core::vector3df pos = node_.getPosition();
	pos.X -= speed_;
	node_.setPosition(pos);
	if (irr::scene::IAnimatedMeshSceneNode *animatedMesh = static_cast<irr::scene::IAnimatedMeshSceneNode *>(&node_))
		animatedMesh->animateJoints();
}

void Character::MoveRight() {
	node_.setRotation(irr::core::vector3df(0, 270, 0));
	irr::core::vector3df pos = node_.getPosition();
	pos.X += speed_;
	node_.setPosition(pos);
	if (irr::scene::IAnimatedMeshSceneNode *animatedMesh = static_cast<irr::scene::IAnimatedMeshSceneNode *>(&node_))
		animatedMesh->animateJoints();
}

void Character::MoveRightUp() {
	node_.setRotation(irr::core::vector3df(0, 210, 0));
	irr::core::vector3df pos = node_.getPosition();
	float length = sqrt((pos.X * pos.X) + (pos.Y * pos.Y) + (pos.Z * pos.Z));

	pos.X += (pos.X / length) * speed_;
	pos.Z += (pos.Z / length) * speed_;
	node_.setPosition(pos);
	if (irr::scene::IAnimatedMeshSceneNode *animatedMesh = static_cast<irr::scene::IAnimatedMeshSceneNode *>(&node_))
		animatedMesh->animateJoints();
}

void Character::MoveRightDown() {
	node_.setRotation(irr::core::vector3df(0, 315, 0));
	irr::core::vector3df pos = node_.getPosition();
	float length = sqrt((pos.X * pos.X) + (pos.Y * pos.Y) + (pos.Z * pos.Z));

	pos.X += (pos.X / length) * speed_;
	pos.Z -= (pos.Z / length) * speed_;
	node_.setPosition(pos);
	if (irr::scene::IAnimatedMeshSceneNode *animatedMesh = static_cast<irr::scene::IAnimatedMeshSceneNode *>(&node_))
		animatedMesh->animateJoints();
}

void Character::MoveLeftUp() {
	node_.setRotation(irr::core::vector3df(0, 135, 0));
	irr::core::vector3df pos = node_.getPosition();
	float length = sqrt((pos.X * pos.X) + (pos.Y * pos.Y) + (pos.Z * pos.Z));

	pos.Z += (pos.Z / length) * speed_;
	pos.X -= (pos.X / length) * speed_;
	node_.setPosition(pos);
	if (irr::scene::IAnimatedMeshSceneNode *animatedMesh = static_cast<irr::scene::IAnimatedMeshSceneNode *>(&node_))
		animatedMesh->animateJoints();
}

void Character::MoveLeftDown() {
	node_.setRotation(irr::core::vector3df(0, 45, 0));
	irr::core::vector3df pos = node_.getPosition();
	float length = sqrt((pos.X * pos.X) + (pos.Y * pos.Y) + (pos.Z * pos.Z));

	pos.X -= (pos.X / length) * speed_;
	pos.Z -= (pos.Z / length) * speed_;
	node_.setPosition(pos);
	if (irr::scene::IAnimatedMeshSceneNode *animatedMesh = static_cast<irr::scene::IAnimatedMeshSceneNode *>(&node_))
		animatedMesh->animateJoints();
}

void Character::Fire() {
	std::chrono::duration<irr::f32> t = std::chrono::duration_cast<std::chrono::duration<irr::f32>>(std::chrono::steady_clock::now() - last_range_atk_time_);
	if (t.count() < range_atk_speed_)
		return;
	irr::core::vector3df start = node_.getPosition();
	start.Y += 35;
	irr::core::vector3df rotation = node_.getRotation();
	irr::core::vector3df end;
	if (rotation.Y == 0) end = irr::core::vector3df(0,0,-1);
	if (rotation.Y == 45) end = irr::core::vector3df(-1,0,-1);
	if (rotation.Y == 90) end = irr::core::vector3df(-1,0,0);
	if (rotation.Y == 135) end = irr::core::vector3df(-1,0,1);
	if (rotation.Y == 180) end = irr::core::vector3df(0,0,1);
	if (rotation.Y == 210) end = irr::core::vector3df(1,0,1);
	if (rotation.Y == 270) end = irr::core::vector3df(1,0,0);
	if (rotation.Y == 315) end = irr::core::vector3df(1,0,-1);
	end.normalize();
	end = start + (end * range_);
	irr::core::line3df line(start, end);
	proj_mngr_.FireProjectile(*this, line);
	last_range_atk_time_ = std::chrono::steady_clock::now();
}

void Character::Update() {
	if (state_ == DYING)  {
		std::chrono::duration<irr::f32> t = std::chrono::duration_cast<std::chrono::duration<irr::f32>>(std::chrono::steady_clock::now() - death_time_);
		if (t.count() > 2.5 && t.count() < 3.5) {
			// if (irr::scene::IAnimatedMeshSceneNode *animatedMesh = static_cast<irr::scene::IAnimatedMeshSceneNode *>(&node_))
			// 	animatedMesh->setFrameLoop(550, 550);
			// irr::core::vector3df pos = node_.getPosition();
			// pos.Y += 70;
			// node_.setPosition(pos);
		} else if (t.count() > 1.8) {
			if (irr::scene::IAnimatedMeshSceneNode *animatedMesh = static_cast<irr::scene::IAnimatedMeshSceneNode *>(&node_))
				animatedMesh->setFrameLoop(550, 550);
			state_ = DEAD;
		}
	}
}
