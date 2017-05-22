#ifndef DESTRUCTIBLEOBJECT_HPP_
# define DESTRUCTIBLEOBJECT_HPP_

# include "irrlicht.h"
# include "Entity.hpp"

class DestructibleObject : public Entity {
public:
	enum State {
		DEFAULT,
		DESTROYED
	};

protected:
	irr::u16 life_;
	State state_;
	void die();

public:
	DestructibleObject(irr::scene::ISceneNode& node);
	virtual ~DestructibleObject();

	virtual const State& GetState();

	virtual void TakeDamage(irr::u32 dmg);
};

#endif /* !DESTRUCTIBLEOBJECT_HPP_ */
