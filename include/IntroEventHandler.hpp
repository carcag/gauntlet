#ifndef INTROEVENTHANDLER_HPP_
# define INTROEVENTHANDLER_HPP_

# include <list>
# include "irrlicht.h"
# include "Entity.hpp"
# include "IEventHandler.hpp"

class IntroEventHandler : public IEventHandler {
public:
	IntroEventHandler();
	~IntroEventHandler();

  void HandleEvent(EventReceiver *receiver, irr::IrrlichtDevice& device, std::list<Entity *>& entities) const;
};

#endif /* !INTROEVENTHANDLER_HPP_ */
