#ifndef LEVEL1UPDATEHANDLER_HPP_
# define LEVEL1UPDATEHANDLER_HPP_

# include <list>
# include "irrlicht.h"
# include "IUpdateHandler.hpp"

class Level1UpdateHandler : public IUpdateHandler {
public:
	Level1UpdateHandler();
	~Level1UpdateHandler();

	void HandleUpdate(std::list<Entity *>& entities) const;
};

#endif /* !LEVEL1UPDATEHANDLER_HPP_ */
