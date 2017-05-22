#ifndef PLAYERCHARACTER_HPP_
# define PLAYERCHARACTER_HPP_

# include <stack>
# include "irrlicht.h"
# include "Command.hpp"
# include "CharacterCommands.hpp"
# include "Character.hpp"
# include "EventReceiver.hpp"

class PlayerCharacter : public Character {
protected:
	// Player 1
	Command *key_z_;
	Command *key_q_;
	Command *key_s_;
	Command *key_d_;
	Command *key_z_d;
	Command *key_z_q;
	Command *key_s_d;
	Command *key_s_q;
	Command *key_space_;
	// Player 2
	Command *key_up_;
	Command *key_left_;
	Command *key_down_;
	Command *key_right_;
	Command *key_up_right;
	Command *key_up_left;
	Command *key_down_right;
	Command *key_down_left;
	Command *key_m_;
	// Player 3 (gamepad)
	Command *stick_up_;
	Command *stick_left_;
	Command *stick_down_;
	Command *stick_right_;
	Command *stick_up_right;
	Command *stick_up_left;
	Command *stick_down_right;
	Command *stick_down_left;
	Command *stick_fire_;

	irr::u32 score_;
	irr::u8 player_id_;
	irr::scene::ICameraSceneNode& camera_;

	std::stack<Command *>& getCommands(EventReceiver *receiver);

public:
	PlayerCharacter(irr::scene::ISceneNode& node, irr::scene::ICameraSceneNode& camera, ProjectileManager& proj_mngr, AI& AI_mngr, irr::u8 player_id = 1);
	virtual ~PlayerCharacter();

	void die();
	virtual void AddScore(irr::u32);
	virtual irr::u8 GetPlayerID();

	virtual void MoveUp();
	virtual void MoveDown();
	virtual void MoveLeft();
	virtual void MoveRight();
	virtual void MoveRightUp();
	virtual void MoveRightDown();
	virtual void MoveLeftUp();
	virtual void MoveLeftDown();

	void Destroy();

	virtual void Events(EventReceiver *receiver);
};

#endif /* !PLAYERCHARACTER_HPP_ */
