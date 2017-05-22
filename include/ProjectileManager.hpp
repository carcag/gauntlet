#ifndef PROJECTILEMANAGER_HPP_
# define PROJECTILEMANAGER_HPP_

# include <list>
# include "irrlicht.h"
# include "Entity.hpp"
# include "Character.hpp"

class Character;

class ProjectileManager {
protected:
	irr::IrrlichtDevice& device_;
	std::list<Entity *>& entities_;

public:
	ProjectileManager(irr::IrrlichtDevice& device, std::list<Entity *>& entities);
	virtual ~ProjectileManager();

	void FireProjectile(Character& ent, irr::core::line3df line);
};

#endif /* !PROJECTILEMANAGER_HPP_ */
