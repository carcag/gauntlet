#ifndef NONPLAYERCHARACTER_HPP_
# define NONPLAYERCHARACTER_HPP_

# include "irrlicht.h"
# include "Command.hpp"
# include "CharacterCommands.hpp"
# include "Character.hpp"
# include "EventReceiver.hpp"

class NonPlayerCharacter : public Character {
public:
	enum AIState {
		IDLE,
		AGGRO
	};

protected:
	irr::u32 points_value_;
	AIState ai_state_;
	irr::s32 order_;
	irr::s32 refresh_;
	irr::s32 aggroRange_;

public:
	NonPlayerCharacter(irr::scene::ISceneNode& node, ProjectileManager& proj_mngr, AI& AI_mngr, int aggroRange);
	virtual ~NonPlayerCharacter();

	virtual const irr::u32& GetPointsValue();
	virtual const AIState& GetAIState();
	virtual const int GetOrder();
	virtual const int GetRefresh();
	virtual const int GetAggroRange();

	virtual const void SetOrder(int i);
	virtual const void SetRefresh(int i);
	virtual const void SetAggroRange(int i);

	virtual void Update();
};

#endif /* !NONPLAYERCHARACTER_HPP_ */
