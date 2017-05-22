#ifndef LIFEPOWERUP_HPP_
# define LIFEPOWERUP_HPP_

# include "irrlicht.h"
# include "PowerUp.hpp"

class LifePowerUp : public PowerUp {
protected:

public:
	LifePowerUp(irr::scene::ISceneNode& node);
	virtual ~LifePowerUp();

	virtual void Buff(Character& c) const;
};

#endif /* !LIFEPOWERUP_HPP_ */
