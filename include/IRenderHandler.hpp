#ifndef IRENDERHANDLER_HPP_
# define IRENDERHANDLER_HPP_

# include "irrlicht.h"

class IRenderHandler {
public:
	virtual ~IRenderHandler() {};

	virtual void HandleRender(irr::IrrlichtDevice& device) const = 0;
};

#endif /* !IRENDERHANDLER_HPP_ */
