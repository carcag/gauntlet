#ifndef PAUSEGAMEUPDATEHANDLER_HPP_
# define PAUSEGAMEUPDATEHANDLER_HPP_

# include <list>
# include "irrlicht.h"
# include "IUpdateHandler.hpp"

class PauseGameUpdateHandler : public IUpdateHandler {
public:
	PauseGameUpdateHandler();
	~PauseGameUpdateHandler();

	void HandleUpdate(std::list<Entity *>& entities) const;
};

#endif /* !PAUSEGAMEUPDATEHANDLER_HPP_ */
