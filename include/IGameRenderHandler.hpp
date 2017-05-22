#ifndef IGAMERENDERHANDLER_HPP_
# define IGAMERENDERHANDLER_HPP_

# include "irrlicht.h"
# include "HUD.hpp"

class IGameRenderHandler {
public:
	virtual ~IGameRenderHandler() {};

	virtual void HandleRender(irr::IrrlichtDevice& device, HUD *hud[4], irr::u16 nb_players, irr::scene::ICameraSceneNode *camera[4]) const = 0;
	virtual void render2Player(irr::IrrlichtDevice& device, HUD *hud[4], irr::scene::ICameraSceneNode *camera[4]) const = 0;
	virtual void render3Player(irr::IrrlichtDevice& device, HUD *hud[4], irr::scene::ICameraSceneNode *camera[4]) const = 0;
	virtual void render4Player(irr::IrrlichtDevice& device, HUD *hud[4], irr::scene::ICameraSceneNode *camera[4]) const = 0;
};

#endif /* !IGAMERENDERHANDLER_HPP_ */
