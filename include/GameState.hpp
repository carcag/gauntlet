#ifndef GAMESTATE_HPP_
# define GAMESTATE_HPP_

# include "irrlicht.h"
# include "IState.hpp"
# include "IGameRenderHandler.hpp"
# include "PowerUp.hpp"
# include "SpeedPowerUp.hpp"
# include "LifePowerUp.hpp"
# include "AtkSpeedPowerUp.hpp"

class GameState : public IState {
protected:
	irr::u16 players_nb_;
	IGameRenderHandler *render_handler_;
	std::list<PowerUp *> powerups_;
	irr::scene::ICameraSceneNode *cameras_[4];
	HUD *huds_[4];
	ProjectileManager *proj_mngr_;
	AI *AI_mngr_;


  virtual irr::scene::IMeshSceneNode *addEntity(irr::IrrlichtDevice& device, irr::scene::IMesh *mesh, const irr::io::path& texture_path, irr::core::vector3df pos, irr::core::vector3df scale, irr::core::vector3df rotation, irr::scene::IMetaTriangleSelector *metaSelector);
  virtual irr::scene::IAnimatedMeshSceneNode *addMob(irr::IrrlichtDevice& device, irr::scene::IAnimatedMesh *mesh, irr::core::vector3df pos, irr::core::vector3df scale, irr::core::vector3df rotation, irr::scene::IMetaTriangleSelector *metaSelector, irr::s32 id, irr::s32 begin, irr::s32 end, irr::f32 speed);
	virtual irr::scene::IAnimatedMeshSceneNode *addPlayer(irr::IrrlichtDevice& device, irr::scene::IAnimatedMesh *mesh, irr::core::vector3df pos, irr::core::vector3df scale, irr::core::vector3df rotation, irr::scene::IMetaTriangleSelector *metaSelector);

public:
	GameState(irr::IrrlichtDevice& device, irr::u16 players_nb);
 	virtual ~GameState();
};

#endif /* !GAMESTATE_HPP_ */
