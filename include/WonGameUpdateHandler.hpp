#ifndef WONGAMEUPDATEHANDLER_HPP_
# define WONGAMEUPDATEHANDLER_HPP_

# include <list>
# include "irrlicht.h"
# include "IUpdateHandler.hpp"

class WonGameUpdateHandler : public IUpdateHandler {
public:
	WonGameUpdateHandler();
	~WonGameUpdateHandler();

	void HandleUpdate(std::list<Entity *>& entities) const;
};

#endif /* !WONGAMEUPDATEHANDLER_HPP_ */
