#ifndef ATKSPEEDPOWERUP_HPP_
# define ATKSPEEDPOWERUP_HPP_

# include "irrlicht.h"
# include "PowerUp.hpp"

class AtkSpeedPowerUp : public PowerUp {
protected:

public:
	AtkSpeedPowerUp(irr::scene::ISceneNode& node);
	virtual ~AtkSpeedPowerUp();

	virtual void Buff(Character& c) const;
};

#endif /* !ATKSPEEDPOWERUP_HPP_ */
