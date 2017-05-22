#ifndef GAMEOVERUPDATEHANDLER_HPP_
# define GAMEOVERUPDATEHANDLER_HPP_

# include <list>
# include "irrlicht.h"
# include "IUpdateHandler.hpp"

class GameOverUpdateHandler : public IUpdateHandler {
public:
	GameOverUpdateHandler();
	~GameOverUpdateHandler();

	void HandleUpdate(std::list<Entity *>& entities) const;
};

#endif /* !GAMEOVERUPDATEHANDLER_HPP_ */
