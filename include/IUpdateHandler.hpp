#ifndef IUPDATEHANDLER_HPP_
# define IUPDATEHANDLER_HPP_

# include "irrlicht.h"
# include "Entity.hpp"

class IUpdateHandler {
public:
	virtual ~IUpdateHandler() {};

	virtual void HandleUpdate(std::list<Entity *>& entities) const = 0;
};

#endif /* !IUPDATEHANDLER_HPP_ */
