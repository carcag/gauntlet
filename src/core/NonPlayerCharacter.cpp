#include "NonPlayerCharacter.hpp"
#include "AI.hpp"

NonPlayerCharacter::NonPlayerCharacter(irr::scene::ISceneNode& node, ProjectileManager& proj_mngr, AI& AI_mngr, int aggroRange) : Character(node, proj_mngr, AI_mngr), points_value_(10), ai_state_(IDLE) {
	AI_EntityType_ = NONPLAYER;
	speed_ = 3;
	order_ = 0;
	refresh_ = 0;
	aggroRange_ = aggroRange;
}

NonPlayerCharacter::~NonPlayerCharacter() {
}

const irr::u32& NonPlayerCharacter::GetPointsValue() {
	return (points_value_);
}
const NonPlayerCharacter::AIState& NonPlayerCharacter::GetAIState() {
	return (ai_state_);
}

const int NonPlayerCharacter::GetOrder(){
	return (order_);
}

const int NonPlayerCharacter::GetRefresh(){
	return (refresh_);
}

const int NonPlayerCharacter::GetAggroRange(){
	return (aggroRange_);
}

const void NonPlayerCharacter::SetOrder(int i){
	order_ = i;
}

const void NonPlayerCharacter::SetRefresh(int i){
	refresh_ = i;
}

const void NonPlayerCharacter::SetAggroRange(int i){
	aggroRange_ = i;
}

void NonPlayerCharacter::Update() {
	Character::Update();
	AI_mngr_.getActions(*this);
}
