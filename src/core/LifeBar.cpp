#include "LifeBar.hpp"

LifeBar::LifeBar(irr::video::IVideoDriver& driver) : driver_(driver) {
	full_heart_ = driver_.getTexture("media/full_heart.png");
	empty_heart_ = driver_.getTexture("media/empty_heart.png");
	character_ = NULL;
}

LifeBar::~LifeBar() {
}

void LifeBar::AttachCharacter(Character *character) {
	character_ = character;
}

void LifeBar::DetachCharacter() {
	character_ = NULL;
}

void LifeBar::Display() {
	if (character_) {
		driver_.draw2DImage((character_->GetLife() >= 1) ? full_heart_ : empty_heart_, irr::core::position2d<irr::s32>(50,50),irr::core::rect<irr::s32>(0,0,40,40), 0,irr::video::SColor(255,255,255,255), true);
		driver_.draw2DImage((character_->GetLife() >= 2) ? full_heart_ : empty_heart_, irr::core::position2d<irr::s32>(90,50),irr::core::rect<irr::s32>(0,0,40,40), 0,irr::video::SColor(255,255,255,255), true);
		driver_.draw2DImage((character_->GetLife() >= 3) ? full_heart_ : empty_heart_, irr::core::position2d<irr::s32>(130,50),irr::core::rect<irr::s32>(0,0,40,40), 0,irr::video::SColor(255,255,255,255), true);
		driver_.draw2DImage((character_->GetLife() >= 4) ? full_heart_ : empty_heart_, irr::core::position2d<irr::s32>(170,50),irr::core::rect<irr::s32>(0,0,40,40), 0,irr::video::SColor(255,255,255,255), true);
	}
}
