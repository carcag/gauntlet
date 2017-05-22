#ifndef WONGAMERENDERHANDLER_HPP_
# define WONGAMERENDERHANDLER_HPP_

# include "irrlicht.h"
# include "IRenderHandler.hpp"

class WonGameRenderHandler : public IRenderHandler {
public:
	WonGameRenderHandler();
	~WonGameRenderHandler();

	void HandleRender(irr::IrrlichtDevice& device) const;
};

#endif /* !WONGAMERENDERHANDLER_HPP_ */
