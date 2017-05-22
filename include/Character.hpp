#ifndef CHARACTER_HPP_
# define CHARACTER_HPP_

# include <chrono>
# include <algorithm>
# include "irrlicht.h"
# include "Entity.hpp"
# include "ProjectileManager.hpp"

class ProjectileManager;
class AI;

class Character : public Entity {
public:
	enum State {
		ALIVE,
		DYING,
		DEAD
	};

protected:
	irr::f32 speed_;
	irr::u32 life_;
	irr::u32 proj_dmg_;
	bool proj_pierce_;
	irr::u32 range_;
	irr::f32 range_atk_speed_;
	State state_;

	ProjectileManager& proj_mngr_;
	AI& AI_mngr_;
	// used to time range attacks and animations
	std::chrono::steady_clock::time_point last_range_atk_time_;
	std::chrono::steady_clock::time_point death_time_;

	void die();

public:
	Character(irr::scene::ISceneNode& node, ProjectileManager& proj_mngr, AI& AI_mngr);
	virtual ~Character();

	virtual const irr::u32& GetLife() const;
	virtual const bool& GetPierce() const;
	virtual const irr::u32& GetRangeDamage() const;
	virtual const irr::f32& GetAtkSpeed() const;
	virtual const State& GetState() const;

	virtual void SetSpeed(irr::f32 speed);
	virtual void SetLife(irr::u32 life);
	virtual void SetAtkSpeed(irr::f32 atkspeed);

	virtual void TakeDamage(irr::u32 dmg);

	virtual void MoveUp();
	virtual void MoveDown();
	virtual void MoveLeft();
	virtual void MoveRight();
	virtual void MoveRightUp();
	virtual void MoveRightDown();
	virtual void MoveLeftUp();
	virtual void MoveLeftDown();
	virtual void Fire();

	virtual void Update();

};

#endif /* !CHARACTER_HPP_ */
