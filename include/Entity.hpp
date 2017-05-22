#ifndef ENTITY_HPP_
# define ENTITY_HPP_

# include "irrlicht.h"

class AI;

class Entity {
public:
	enum AI_EntityType {
		PLAYER,
		NONPLAYER,
		WALL,
		OBJECT
	};


protected:
	irr::scene::ISceneNode& node_;
	AI_EntityType AI_EntityType_;
public:
	Entity(irr::scene::ISceneNode& node);
	virtual ~Entity();

	virtual void SetPos(irr::core::vector3df pos);
	virtual const irr::core::vector3df& GetPos() const;
	virtual const irr::core::vector3df& GetRot() const;
	virtual irr::s32 GetID() const;
	virtual irr::scene::ITriangleSelector *GetTriangleSelector() const;
	virtual Entity::AI_EntityType GetAIState() const;


	virtual void Update();

	virtual void Remove();
};

#endif /* !ENTITY_HPP_ */
