#include "AtkSpeedPowerUp.hpp"

AtkSpeedPowerUp::AtkSpeedPowerUp(irr::scene::ISceneNode& node) : PowerUp(node) {
}

AtkSpeedPowerUp::~AtkSpeedPowerUp() {
}

void AtkSpeedPowerUp::Buff(Character& c) const {
	c.SetAtkSpeed(c.GetAtkSpeed() / 2);
	PowerUp::Buff(c);
}
