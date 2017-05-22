#ifndef GAMEOVERSTATE_HPP_
# define GAMEOVERSTATE_HPP_

# include "irrlicht.h"
# include "IState.hpp"
# include "GameOverEventHandler.hpp"
# include "GameOverUpdateHandler.hpp"
# include "GameOverRenderHandler.hpp"

enum {
	REREREQUIT_BUTTON,
	REREREMENU_BUTTON,
	REREREBUTTON_NB
};

class GameOverState : public IState {
protected:
	void init();
	void drop();

public:
	GameOverState(irr::IrrlichtDevice& device);
	virtual ~GameOverState();

	void Events(EventReceiver *receiver);
	void Update();
	void Render();

private:
	irr::gui::IGUIButton* restart_;
	irr::gui::IGUIButton* quit_;
	irr::gui::IGUIButton* menu_;
};

#endif /* !GAMEOVERSTATE_HPP_ */
