#ifndef INTROSTATE_HPP_
# define INTROSTATE_HPP_

# include "irrlicht.h"
# include "IState.hpp"
# include "IntroEventHandler.hpp"
# include "IntroUpdateHandler.hpp"
# include "IntroRenderHandler.hpp"

class IntroState : public IState {
protected:
	void init();
	void drop();

public:
	IntroState(irr::IrrlichtDevice& device);
	virtual ~IntroState();

	void Events(EventReceiver *receiver);
	void Update();
	void Render();
};

#endif /* !INTROSTATE_HPP_ */
