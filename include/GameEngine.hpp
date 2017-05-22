#ifndef GAMEENGINE_HPP_
# define GAMEENGINE_HPP_

# include <stack>
# include "irrlicht.h"
# include "StateManager.hpp"
# include "EventReceiver.hpp"

class GameEngine {
private:
	StateManager *state_manager_;
	irr::IrrlichtDevice *device_;
	EventReceiver *event_receiver_;

public:
	GameEngine();
	~GameEngine();

	bool Run();
	irr::IrrlichtDevice& GetDevice() const;

	void Events();
	void Update();
	void Render();
	void ResetKeys();
};

#endif /* !GAMEENGINE_HPP_ */
