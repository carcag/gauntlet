#ifndef SPEEDPOWERUP_HPP_
# define SPEEDPOWERUP_HPP_

# include "irrlicht.h"
# include "PowerUp.hpp"

class SpeedPowerUp : public PowerUp {
protected:

public:
	SpeedPowerUp(irr::scene::ISceneNode& node);
	virtual ~SpeedPowerUp();

	virtual void Buff(Character& c) const;
};

#endif /* !SPEEDPOWERUP_HPP_ */
