#ifndef PAUSEGAMERENDERHANDLER_HPP_
# define PAUSEGAMERENDERHANDLER_HPP_

# include "irrlicht.h"
# include "IRenderHandler.hpp"

class PauseGameRenderHandler : public IRenderHandler {
public:
	PauseGameRenderHandler();
	~PauseGameRenderHandler();

	void HandleRender(irr::IrrlichtDevice& device) const;
};

#endif /* !PAUSEGAMERENDERHANDLER_HPP_ */
