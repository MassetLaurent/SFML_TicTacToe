#ifndef DEF_STATE_MACHINE
#define DEF_STATE_MACHINE

#include <memory>
#include <stack>

#include "State.h"

typedef std::unique_ptr<State> StateRef;

class StateMachine
{
private:
	std::stack<StateRef> states;
	StateRef newState;

	bool isReplacing;
	bool isRemoving;
	bool isAdding;

public:
	StateMachine() {}
	~StateMachine() {}

	void addState(StateRef _newState, bool _isReplacing = true);
	void removeState();
	void processStateChanges();

	StateRef &getActiveState();
};

#endif // !DEF_STATE_MACHINE