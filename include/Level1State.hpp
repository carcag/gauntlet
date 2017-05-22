#ifndef LEVEL1STATE_HPP_
# define LEVEL1STATE_HPP_

# include "irrlicht.h"
# include "HUD.hpp"
# include "LifeBar.hpp"
# include "GameState.hpp"
# include "Level1EventHandler.hpp"
# include "Level1UpdateHandler.hpp"
# include "Level1RenderHandler.hpp"
# include "ProjectileManager.hpp"

class Level1State : public GameState {
protected:
	void init();
	void initLoad(std::vector<std::string> tabinfo);
	void drop();
	void genMap(irr::scene::IMetaTriangleSelector* metaSelector, std::list<PowerUp *>& powerups);

public:
	Level1State(irr::IrrlichtDevice& device, irr::u16 players_nb);
	Level1State(irr::IrrlichtDevice& device, irr::u16 players_nb, std::vector<std::string> tabinfo);
	virtual ~Level1State();

	void Events(EventReceiver *receiver);
	void Update();
	void Render();
};

#endif /* !LEVEL1STATE_HPP_ */
