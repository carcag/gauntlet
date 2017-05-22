#ifndef HUD_HPP_
# define HUD_HPP_

# include <list>
# include "irrlicht.h"
# include "LifeBar.hpp"
# include "IHUDModule.hpp"

class HUD {
protected:
	std::list<IHUDModule *> modules_; //
	LifeBar *lifebar_;

public:
	HUD();
	virtual ~HUD();

	void AddModule(IHUDModule *module); //
	void SetLifeBarModule(LifeBar *lifebar);
	LifeBar& GetLifeBarModule() const;

	void Display();
};

#endif /* !HUD_HPP_ */
