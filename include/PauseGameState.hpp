#ifndef PAUSEGAMESTATE_HPP_
# define PAUSEGAMESTATE_HPP_

# include "irrlicht.h"
# include "Entity.hpp"
# include "IState.hpp"
# include "PauseGameEventHandler.hpp"
# include "PauseGameUpdateHandler.hpp"
# include "PauseGameRenderHandler.hpp"

enum {
	RELAUNCH_BUTTON,
	SAVE_BUTTON,
	REQUIT_BUTTON,
	MENU_BUTTON,
	REBUTTON_NB
};

class PauseGameState : public IState {
protected:
	void init();
	void drop();

public:
	PauseGameState(irr::IrrlichtDevice& device);
  PauseGameState(irr::IrrlichtDevice& device, std::list<Entity *>& entities);
	virtual ~PauseGameState();

	void Events(EventReceiver *receiver);
	void Update();
	void Render();

private:
	irr::gui::IGUIButton* restart_;
	irr::gui::IGUIButton* save_;
	irr::gui::IGUIButton* quit_;
	irr::gui::IGUIButton* menu_;
	irr::u16 players_nb_;
};

#endif /* !PAUSEGAMESTATE_HPP_ */
