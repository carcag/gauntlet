#include "SpeedPowerUp.hpp"

SpeedPowerUp::SpeedPowerUp(irr::scene::ISceneNode& node) : PowerUp(node) {
}

SpeedPowerUp::~SpeedPowerUp() {
}

void SpeedPowerUp::Buff(Character& c) const {
	c.SetSpeed(10);
	PowerUp::Buff(c);
}
