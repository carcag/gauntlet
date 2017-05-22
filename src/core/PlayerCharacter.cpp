#include "PlayerCharacter.hpp"

PlayerCharacter::PlayerCharacter(irr::scene::ISceneNode& node, irr::scene::ICameraSceneNode& camera, ProjectileManager& proj_mngr, AI& AI_mngr, irr::u8 player_id) : Character(node, proj_mngr, AI_mngr), camera_(camera), player_id_(player_id), score_(0) {
	if (player_id_ == 1) {
		key_z_ = new MoveUpCommand;
		key_z_d = new MoveRightUpCommand;
		key_z_q = new MoveLeftUpCommand;
		key_s_d = new MoveRightDownCommand;
		key_s_q = new MoveLeftDownCommand;
		key_s_ = new MoveDownCommand;
		key_q_ = new MoveLeftCommand;
		key_d_ = new MoveRightCommand;
		key_space_ = new FireCommand;
	} else if (player_id_ == 2) {
		key_up_ = new MoveUpCommand;
		key_up_right = new MoveRightUpCommand;
		key_up_left = new MoveLeftUpCommand;
		key_down_right = new MoveRightDownCommand;
		key_down_left = new MoveLeftDownCommand;
		key_down_ = new MoveDownCommand;
		key_left_ = new MoveLeftCommand;
		key_right_ = new MoveRightCommand;
		key_m_ = new FireCommand;
	} else if (player_id_ == 3) {
		stick_up_ = new MoveUpCommand;
		stick_left_ = new MoveLeftCommand;
		stick_down_ = new MoveDownCommand;
		stick_right_ = new MoveRightCommand;
		stick_up_right = new MoveRightUpCommand;
		stick_up_left = new MoveLeftUpCommand;
		stick_down_right = new MoveRightDownCommand;
		stick_down_left = new MoveLeftDownCommand;
		stick_fire_ = new FireCommand;
	}
	AI_EntityType_ = PLAYER;
}

PlayerCharacter::~PlayerCharacter() {
}

std::stack<Command *>& PlayerCharacter::getCommands(EventReceiver *receiver) {
	std::stack<Command *> *stack = new std::stack<Command *>;

	if (player_id_ == 1) {
		if (receiver->IsKeyDown(irr::KEY_SPACE)) stack->push(key_space_);
		if (receiver->IsKeyDown(irr::KEY_KEY_Z) && receiver->IsKeyDown(irr::KEY_KEY_D)) {
			stack->push(key_z_d);
			return (*stack);
		}
		if (receiver->IsKeyDown(irr::KEY_KEY_Z) && receiver->IsKeyDown(irr::KEY_KEY_Q)) {
			stack->push(key_z_q);
			return (*stack);
		}
		if (receiver->IsKeyDown(irr::KEY_KEY_S) && receiver->IsKeyDown(irr::KEY_KEY_D)) {
			stack->push(key_s_d);
			return (*stack);
		}
		if (receiver->IsKeyDown(irr::KEY_KEY_S) && receiver->IsKeyDown(irr::KEY_KEY_Q)) {
			stack->push(key_s_q);
			return (*stack);
		}
		if (receiver->IsKeyDown(irr::KEY_KEY_Z)) stack->push(key_z_);
		if (receiver->IsKeyDown(irr::KEY_KEY_S)) stack->push(key_s_);
		if (receiver->IsKeyDown(irr::KEY_KEY_Q)) stack->push(key_q_);
		if (receiver->IsKeyDown(irr::KEY_KEY_D)) stack->push(key_d_);
		return (*stack);
	} else if (player_id_ == 2) {
		if (receiver->IsKeyDown(irr::KEY_KEY_M)) stack->push(key_m_);
		if (receiver->IsKeyDown(irr::KEY_UP) && receiver->IsKeyDown(irr::KEY_RIGHT)) {
			stack->push(key_up_right);
			return (*stack);
		}
		if (receiver->IsKeyDown(irr::KEY_UP) && receiver->IsKeyDown(irr::KEY_LEFT)) {
			stack->push(key_up_left);
			return (*stack);
		}
		if (receiver->IsKeyDown(irr::KEY_DOWN) && receiver->IsKeyDown(irr::KEY_RIGHT)) {
			stack->push(key_down_right);
			return (*stack);
		}
		if (receiver->IsKeyDown(irr::KEY_DOWN) && receiver->IsKeyDown(irr::KEY_LEFT)) {
			stack->push(key_down_left);
			return (*stack);
		}
		if (receiver->IsKeyDown(irr::KEY_UP)) stack->push(key_up_);
		if (receiver->IsKeyDown(irr::KEY_DOWN)) stack->push(key_down_);
		if (receiver->IsKeyDown(irr::KEY_LEFT)) stack->push(key_left_);
		if (receiver->IsKeyDown(irr::KEY_RIGHT)) stack->push(key_right_);
		return (*stack);
	} else if (player_id_ == 3) {
		const irr::SEvent::SJoystickEvent& js_state = receiver->GetJoystickState();
		const irr::f32 DEAD_ZONE = 0.15f;
		irr::f32 moveHorizontal = 0.f;
		irr::f32 moveVertical = 0.f;

		moveHorizontal = (irr::f32)js_state.Axis[irr::SEvent::SJoystickEvent::AXIS_X] / 32767.f;
		if(fabs(moveHorizontal) < DEAD_ZONE)
			moveHorizontal = 0.f;
		moveVertical = (irr::f32)js_state.Axis[irr::SEvent::SJoystickEvent::AXIS_Y] / -32767.f;
		if(fabs(moveVertical) < DEAD_ZONE)
			moveVertical = 0.f;
		// POV hat info is only currently supported on Windows, but the value is
		// guaranteed to be 65535 if it's not supported, so we can check its range.
		const irr::u16 povDegrees = js_state.POV / 100;
		if(povDegrees < 360)
		{
			if(povDegrees > 0 && povDegrees < 180)
				moveHorizontal = 1.f;
			else if(povDegrees > 180)
				moveHorizontal = -1.f;

			if(povDegrees > 90 && povDegrees < 270)
				moveVertical = -1.f;
			else if(povDegrees > 270 || povDegrees < 90)
				moveVertical = +1.f;
		}
		if (js_state.Axis[5] > 25000) stack->push(stick_fire_);
		if (moveHorizontal > 0 && moveVertical > 0) {
			stack->push(stick_up_right);
			return (*stack);
		}
		if (moveHorizontal > 0 && moveVertical < 0) {
			stack->push(stick_down_right);
			return (*stack);
		}
		if (moveHorizontal < 0 && moveVertical > 0) {
			stack->push(stick_up_left);
			return (*stack);
		}
		if (moveHorizontal < 0 && moveVertical < 0) {
			stack->push(stick_down_left);
			return (*stack);
		}
		if (moveVertical > 0 ) stack->push(stick_up_);
		if (moveVertical < 0 ) stack->push(stick_down_);
		if (moveHorizontal > 0) stack->push(stick_right_);
		if (moveHorizontal < 0) stack->push(stick_left_);
		return (*stack);
	}
}

void PlayerCharacter::die() {
		state_ = DEAD;
}

void PlayerCharacter::Destroy() {
		node_.setPosition(irr::core::vector3df(50000));
}

irr::u8 PlayerCharacter::GetPlayerID() {
	return (player_id_);
}

void PlayerCharacter::Events(EventReceiver *receiver) {
	std::stack<Command *>& cmd_stack = getCommands(receiver);

	while (!cmd_stack.empty()) {
		cmd_stack.top()->Execute(*this);
		cmd_stack.pop();
	}
	delete &cmd_stack;
}

void PlayerCharacter::AddScore(irr::u32 score) {
	score_ += score;
	printf("new score : %d\n", score_);
}

void PlayerCharacter::MoveUp() {
	Character::MoveUp();
	irr::core::vector3df pos = node_.getPosition();
	camera_.setPosition(irr::core::vector3df(pos.X, 400, pos.Z - 300));
	camera_.setTarget(pos);
}

void PlayerCharacter::MoveDown() {
	Character::MoveDown();
	irr::core::vector3df pos = node_.getPosition();
	camera_.setPosition(irr::core::vector3df(pos.X, 400, pos.Z - 300));
	camera_.setTarget(pos);
}

void PlayerCharacter::MoveLeft() {
	Character::MoveLeft();
	irr::core::vector3df pos = node_.getPosition();
	camera_.setPosition(irr::core::vector3df(pos.X, 400, pos.Z - 300));
	camera_.setTarget(pos);
}

void PlayerCharacter::MoveRight() {
	Character::MoveRight();
	irr::core::vector3df pos = node_.getPosition();
	camera_.setPosition(irr::core::vector3df(pos.X, 400, pos.Z - 300));
	camera_.setTarget(pos);
}

void PlayerCharacter::MoveLeftUp() {
	Character::MoveLeftUp();
	irr::core::vector3df pos = node_.getPosition();
	camera_.setPosition(irr::core::vector3df(pos.X, 400, pos.Z - 300));
	camera_.setTarget(pos);
}

void PlayerCharacter::MoveLeftDown() {
	Character::MoveLeftDown();
	irr::core::vector3df pos = node_.getPosition();
	camera_.setPosition(irr::core::vector3df(pos.X, 400, pos.Z - 300));
	camera_.setTarget(pos);
}

void PlayerCharacter::MoveRightUp() {
	Character::MoveRightUp();
	irr::core::vector3df pos = node_.getPosition();
	camera_.setPosition(irr::core::vector3df(pos.X, 400, pos.Z - 300));
	camera_.setTarget(pos);
}

void PlayerCharacter::MoveRightDown() {
	Character::MoveRightDown();
	irr::core::vector3df pos = node_.getPosition();
	camera_.setPosition(irr::core::vector3df(pos.X, 400, pos.Z - 300));
	camera_.setTarget(pos);
}
