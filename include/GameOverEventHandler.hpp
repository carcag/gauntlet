#ifndef GAMEOVEREVENTHANDLER_HPP_
# define GAMEOVEREVENTHANDLER_HPP_

# include <list>
# include "irrlicht.h"
# include "Entity.hpp"
# include "IEventHandler.hpp"

class GameOverEventHandler : public IEventHandler {
public:
	GameOverEventHandler();
	~GameOverEventHandler();

	void HandleEvent(EventReceiver *receiver, irr::IrrlichtDevice& device, std::list<Entity *>& entities) const;
};

#endif /* !GAMEOVEREVENTHANDLER_HPP_ */
