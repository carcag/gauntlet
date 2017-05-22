#ifndef INTROUPDATEHANDLER_HPP_
# define INTROUPDATEHANDLER_HPP_

# include <list>
# include "irrlicht.h"
# include "IUpdateHandler.hpp"

class IntroUpdateHandler : public IUpdateHandler {
public:
	IntroUpdateHandler();
	~IntroUpdateHandler();

	void HandleUpdate(std::list<Entity *>& entities) const;
};

#endif /* !INTROUPDATEHANDLER_HPP_ */
