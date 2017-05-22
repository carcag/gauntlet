#ifndef WONGAMEEVENTHANDLER_HPP_
# define WONGAMEEVENTHANDLER_HPP_

# include <list>
# include "irrlicht.h"
# include "Entity.hpp"
# include "IEventHandler.hpp"

class WonGameEventHandler : public IEventHandler {
public:
	WonGameEventHandler();
	~WonGameEventHandler();

	void HandleEvent(EventReceiver *receiver, irr::IrrlichtDevice& device, std::list<Entity *>& entities) const;
};

#endif /* !WONGAMEEVENTHANDLER_HPP_ */
