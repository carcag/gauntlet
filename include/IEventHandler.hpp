#ifndef IEVENTHANDLER_HPP_
# define IEVENTHANDLER_HPP_

# include <list>
# include "irrlicht.h"
# include "Entity.hpp"
# include "EventReceiver.hpp"

class IEventHandler {
public:
	virtual ~IEventHandler() {};

  virtual void HandleEvent(EventReceiver *receiver, irr::IrrlichtDevice& device, std::list<Entity *>& entities) const = 0;
};

#endif /* !IEVENTHANDLER_HPP_ */
