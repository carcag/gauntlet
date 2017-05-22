#ifndef MENUUPDATEHANDLER_HPP_
# define MENUUPDATEHANDLER_HPP_

# include <list>
# include "irrlicht.h"
# include "IUpdateHandler.hpp"

class MenuUpdateHandler : public IUpdateHandler {
public:
	MenuUpdateHandler();
	~MenuUpdateHandler();

	void HandleUpdate(std::list<Entity *>& entities) const;
};

#endif /* !MENUUPDATEHANDLER_HPP_ */
