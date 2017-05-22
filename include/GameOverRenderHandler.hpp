#ifndef GAMEOVERRENDERHANDLER_HPP_
# define GAMEOVERRENDERHANDLER_HPP_

# include "irrlicht.h"
# include "IRenderHandler.hpp"

class GameOverRenderHandler : public IRenderHandler {
public:
	GameOverRenderHandler();
	~GameOverRenderHandler();

	void HandleRender(irr::IrrlichtDevice& device) const;
};

#endif /* !GAMEOVERRENDERHANDLER_HPP_ */
