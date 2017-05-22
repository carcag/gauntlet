#ifndef MENURENDERHANDLER_HPP_
# define MENURENDERHANDLER_HPP_

# include "irrlicht.h"
# include "IRenderHandler.hpp"

class MenuRenderHandler : public IRenderHandler {
public:
	MenuRenderHandler();
	~MenuRenderHandler();

	void HandleRender(irr::IrrlichtDevice& device) const;
};

#endif /* !MENURENDERHANDLER_HPP_ */
