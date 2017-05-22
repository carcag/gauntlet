#include "Entity.hpp"
#include "AI.hpp"

Entity::Entity(irr::scene::ISceneNode& node) : node_(node) {
	AI_EntityType_ = WALL;
}

Entity::~Entity() {
}

void Entity::SetPos(irr::core::vector3df pos) {
	node_.setPosition(pos);
}

const irr::core::vector3df& Entity::GetPos() const {
	return (node_.getPosition());
}

const irr::core::vector3df& Entity::GetRot() const {
	return (node_.getRotation());
}

irr::s32 Entity::GetID() const {
	return (node_.getID());
}

irr::scene::ITriangleSelector *Entity::GetTriangleSelector() const {
	return (node_.getTriangleSelector());
}

Entity::AI_EntityType Entity::GetAIState() const {
	return (AI_EntityType_);
}

void Entity::Update() {
}

void Entity::Remove() {
}
