#pragma once

class State;
class Agent;

class StateMachine
{
public:
	

	StateMachine();
	~StateMachine();

	void update(Agent* pAgent);
	void changeState(State* newState);

	State* m_currentState = nullptr;
	State* m_prevState = nullptr;
	State* m_nextState = nullptr;
};

