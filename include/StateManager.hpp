#ifndef STATEMANAGER_HPP_
# define STATEMANAGER_HPP_

# include <stack>
# include "IState.hpp"

class StateManager {
private:
	std::stack<IState *> states_;

public:
	static StateManager *Instance();
	~StateManager();

	void Replace(IState *state);
	void Push(IState *state);
	void Pop();
	bool HasActiveState() const;
	IState *GetActiveState();

private:
	StateManager();
};

#endif /* !STATEMANAGER_HPP_ */
