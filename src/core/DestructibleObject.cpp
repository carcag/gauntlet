#include <algorithm>
#include "DestructibleObject.hpp"

DestructibleObject::DestructibleObject(irr::scene::ISceneNode& node) : Entity(node), life_(5), state_(DEFAULT) {
}

DestructibleObject::~DestructibleObject() {
}

void DestructibleObject::die() {
	state_ = DESTROYED;
	node_.setPosition(irr::core::vector3df(50000));
}

const DestructibleObject::State& DestructibleObject::GetState() {
	return (state_);
}

void DestructibleObject::TakeDamage(irr::u32 dmg) {
	life_ = std::max(irr::u32(0), life_ - dmg);
	if (life_ == 0)
		die();
}
