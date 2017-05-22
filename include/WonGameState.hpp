#ifndef WONGAMESTATE_HPP_
# define WONGAMESTATE_HPP_

# include "irrlicht.h"
# include "IState.hpp"
# include "WonGameEventHandler.hpp"
# include "WonGameUpdateHandler.hpp"
# include "WonGameRenderHandler.hpp"

enum {
	REREQUIT_BUTTON,
	REREMENU_BUTTON,
	REREBUTTON_NB
};

class WonGameState : public IState {
protected:
	void init();
	void drop();

public:
	WonGameState(irr::IrrlichtDevice& device);
	virtual ~WonGameState();

	void Events(EventReceiver *receiver);
	void Update();
	void Render();

private:
	irr::gui::IGUIButton* quit_;
	irr::gui::IGUIButton* menu_;
};

#endif /* !WONGAMESTATE_HPP_ */
