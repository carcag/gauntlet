#ifndef LIFEBAR_HPP_
# define LIFEBAR_HPP_

# include "irrlicht.h"
# include "Character.hpp"

class LifeBar {
protected:
	irr::video::IVideoDriver& driver_;
	irr::video::ITexture *full_heart_;
	irr::video::ITexture *empty_heart_;
	Character *character_;

public:
	LifeBar(irr::video::IVideoDriver& driver);
	virtual ~LifeBar();

	virtual void AttachCharacter(Character *character);
	virtual void DetachCharacter();
	virtual void Display();
};

#endif /* !LIFEBAR_HPP_ */
