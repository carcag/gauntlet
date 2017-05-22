#ifndef LEVEL1EVENTHANDLER_HPP_
# define LEVEL1EVENTHANDLER_HPP_

# include <list>
# include "irrlicht.h"
# include "Entity.hpp"
# include "IEventHandler.hpp"

class Level1EventHandler : public IEventHandler {
public:
	Level1EventHandler();
	~Level1EventHandler();

  void HandleEvent(EventReceiver *receiver, irr::IrrlichtDevice& device, std::list<Entity *>& entities) const;
};

#endif /* !LEVEL1EVENTHANDLER_HPP_ */
