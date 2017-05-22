#ifndef AI_CPP_
# define  AI_CPP_

# include <string>
# include <iostream>
# include <list>
# include <sstream>
# include <cmath>
# include "NonPlayerCharacter.hpp"

class NonPlayerCharacter;

class AI {
protected:
	std::list<Entity *>& entities_;
    std::list<std::string> parsedList_;
    std::list<std::string> playerList_;
	std::string parsedCaller_;

public:
	AI(std::list<Entity *>& entList);
	~AI();
	void getActions(NonPlayerCharacter &callChar);
	std::string makeString();
	void makeStringCaller(NonPlayerCharacter& callChar);
	int setAction(NonPlayerCharacter& CallChar);
	void extractPlayer();
	std::string extractNearestPlayer(irr::f32 CposX, irr::f32 CPosY);
};

#endif /*AI_CPP_*/
