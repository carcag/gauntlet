#include "PowerUp.hpp"

PowerUp::PowerUp(irr::scene::ISceneNode& node) : Entity(node) {
}

PowerUp::~PowerUp() {
}

void PowerUp::Buff(Character& c) const {
	node_.setPosition(irr::core::vector3df(50000));
}
