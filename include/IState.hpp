#ifndef ISTATE_HPP_
# define ISTATE_HPP_

# include <list>
# include "irrlicht.h"
# include "Entity.hpp"
# include "EventReceiver.hpp"
# include "IEventHandler.hpp"
# include "IUpdateHandler.hpp"
# include "IRenderHandler.hpp"

class IState {
protected:
	IEventHandler *event_handler_;
	IUpdateHandler *update_handler_;
	IRenderHandler *render_handler_;
	std::list<Entity *> entities_;
	irr::IrrlichtDevice& device_;

	virtual void init() = 0;
	virtual void drop() = 0;

public:
	IState(irr::IrrlichtDevice& device) : device_(device) {};
	IState(irr::IrrlichtDevice& device, std::list<Entity *> entities) : device_(device), entities_(entities) {};
	virtual ~IState() {};

	virtual void Events(EventReceiver *receiver) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

private:
	IState();
};

#endif /* !ISTATE_HPP_ */
