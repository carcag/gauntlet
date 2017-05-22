#ifndef CHARACTERCOMMANDS_HPP_
# define CHARACTERCOMMANDS_HPP_

# include "Command.hpp"

class MoveUpCommand : public Command {
public:
	virtual void Execute(Character& c) { c.MoveUp(); };
};

class MoveDownCommand : public Command {
public:
	virtual void Execute(Character& c) { c.MoveDown(); };
};

class MoveLeftCommand : public Command {
public:
	virtual void Execute(Character& c) { c.MoveLeft(); };
};

class MoveRightCommand : public Command {
public:
	virtual void Execute(Character& c) { c.MoveRight(); };
};

class MoveRightUpCommand : public Command {
public:
	virtual void Execute(Character& c) { c.MoveRightUp(); };
};

class MoveLeftUpCommand : public Command {
public:
	virtual void Execute(Character& c) { c.MoveLeftUp(); };
};

class MoveRightDownCommand : public Command {
public:
	virtual void Execute(Character& c) { c.MoveRightDown(); };
};

class MoveLeftDownCommand : public Command {
public:
	virtual void Execute(Character& c) { c.MoveLeftDown(); };
};

class FireCommand : public Command {
public:
	virtual void Execute(Character& c) { c.Fire(); };
};

#endif /* !CHARACTERCOMMANDS_HPP_ */
