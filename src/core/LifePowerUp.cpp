#include "LifePowerUp.hpp"

LifePowerUp::LifePowerUp(irr::scene::ISceneNode& node) : PowerUp(node) {
}

LifePowerUp::~LifePowerUp() {
}

void LifePowerUp::Buff(Character& c) const {
	c.SetLife(c.GetLife() + 2);
	PowerUp::Buff(c);
}
