#ifndef COMMAND_HPP_
# define COMMAND_HPP_

# include "Character.hpp"

class Command {
public:
	virtual ~Command() {}

	virtual void Execute(Character& c) = 0;
};

#endif /* !COMMAND_HPP_ */
