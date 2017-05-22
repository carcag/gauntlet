#ifndef MENUEVENTHANDLER_HPP_
# define MENUEVENTHANDLER_HPP_

# include <list>
# include "irrlicht.h"
# include "Entity.hpp"
# include "IEventHandler.hpp"

class MenuEventHandler : public IEventHandler {
public:
	MenuEventHandler();
	~MenuEventHandler();

  void HandleEvent(EventReceiver *receiver, irr::IrrlichtDevice& device, std::list<Entity *>& entities) const;
};

#endif /* !MENUEVENTHANDLER_HPP_ */
