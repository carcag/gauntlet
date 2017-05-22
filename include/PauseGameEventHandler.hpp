#ifndef PAUSEGAMEEVENTHANDLER_HPP_
# define PAUSEGAMEEVENTHANDLER_HPP_

# include <list>
# include "irrlicht.h"
# include "Entity.hpp"
# include "IEventHandler.hpp"

class PauseGameEventHandler : public IEventHandler {
public:
	PauseGameEventHandler();
	~PauseGameEventHandler();

  void HandleEvent(EventReceiver *receiver, irr::IrrlichtDevice& device, std::list<Entity *>& entities) const;
};

#endif /* !PAUSEGAMEEVENTHANDLER_HPP_ */
