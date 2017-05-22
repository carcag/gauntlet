#ifndef MENUSTATE_HPP_
# define MENUSTATE_HPP_

# include "irrlicht.h"
# include "IState.hpp"
# include "MenuEventHandler.hpp"
# include "MenuUpdateHandler.hpp"
# include "MenuRenderHandler.hpp"
// # include "AudioHandler.hpp"

enum {
		LAUNCH_BUTTON,
		MULTI2_BUTTON,
		MULTI3_BUTTON,
		MULTI4_BUTTON,
		LOAD_BUTTON,
		QUIT_BUTTON,
		BUTTON_NB
};

class MenuState : public IState {
protected:
 	// AudioHandler mixer;

	void init();
	void drop();

public:
	MenuState(irr::IrrlichtDevice& device);
	virtual ~MenuState();

	void Events(EventReceiver *receiver);
	void Update();
	void Render();

private:
	irr::gui::IGUIButton* start_;
	irr::gui::IGUIButton* multi2_;
	irr::gui::IGUIButton* multi3_;
	irr::gui::IGUIButton* multi4_;
	irr::gui::IGUIButton* load_;
	irr::gui::IGUIButton* quit_;
};

#endif /* !MENUSTATE_HPP_ */
