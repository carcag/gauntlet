#ifndef INTRORENDERHANDLER_HPP_
# define INTRORENDERHANDLER_HPP_

# include "irrlicht.h"
# include "IRenderHandler.hpp"

class IntroRenderHandler : public IRenderHandler {
public:
	IntroRenderHandler();
	~IntroRenderHandler();

	void HandleRender(irr::IrrlichtDevice& device) const;
};

#endif /* !INTRORENDERHANDLER_HPP_ */
