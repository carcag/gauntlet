#ifndef IHUDModule_HPP_
# define IHUDModule_HPP_

# include "irrlicht.h"

class IHUDModule {
protected:
	irr::video::IVideoDriver& driver_;

public:
	IHUDModule(irr::video::IVideoDriver& driver) : driver_(driver) {};
	virtual ~IHUDModule() {};

	virtual void Display() = 0;
};

#endif /* !IHUDModule_HPP_ */
