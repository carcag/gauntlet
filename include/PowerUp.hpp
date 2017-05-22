#ifndef POWERUP_HPP_
# define POWERUP_HPP_

# include "irrlicht.h"
# include "Entity.hpp"
# include "Character.hpp"

class PowerUp : public Entity {
protected:

public:
	PowerUp(irr::scene::ISceneNode& node);
	virtual ~PowerUp();

	virtual void Buff(Character& c) const;
};

#endif /* !POWERUP_HPP_ */
