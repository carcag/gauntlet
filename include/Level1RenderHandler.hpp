#ifndef LEVEL1RENDERHANDLER_HPP_
# define LEVEL1RENDERHANDLER_HPP_

# include "irrlicht.h"
# include "HUD.hpp"
# include "IGameRenderHandler.hpp"

class Level1RenderHandler : public IGameRenderHandler {
public:
	Level1RenderHandler();
	~Level1RenderHandler();

	virtual void HandleRender(irr::IrrlichtDevice& device, HUD *hud[4], irr::u16 nb_players, irr::scene::ICameraSceneNode *camera[4]) const;

private:
	virtual void	render2Player(irr::IrrlichtDevice& device, HUD *hud[4], irr::scene::ICameraSceneNode *camera[4]) const;
	virtual void	render3Player(irr::IrrlichtDevice& device, HUD *hud[4], irr::scene::ICameraSceneNode *camera[4]) const;
	virtual void	render4Player(irr::IrrlichtDevice& device, HUD *hud[4], irr::scene::ICameraSceneNode *camera[4]) const;
};

#endif /* !LEVEL1RENDERHANDLER_HPP_ */
