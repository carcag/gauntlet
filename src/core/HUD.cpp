#include "HUD.hpp"

HUD::HUD() {
	lifebar_ = NULL;
}

HUD::~HUD() {
	if (lifebar_)
		delete lifebar_;
	for (std::list<IHUDModule *>::iterator it = modules_.begin(); it != modules_.end(); it++) {
		delete *it;
	}
}

void HUD::SetLifeBarModule(LifeBar *lifebar) {
	lifebar_ = lifebar;
}

LifeBar& HUD::GetLifeBarModule() const {
	return (*lifebar_);
}

void HUD::AddModule(IHUDModule *module) {
	modules_.push_back(module);
}

void HUD::Display() {
	for (std::list<IHUDModule *>::const_iterator it = modules_.begin(); it != modules_.end(); it++) {
		(*it)->Display();
	}
	if (lifebar_)
		lifebar_->Display();
}
