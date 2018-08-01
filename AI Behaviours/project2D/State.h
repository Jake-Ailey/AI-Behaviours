#pragma once
#include "Agent.h"

class StateMachine;		//Forward declare because heck

class State
{
public:
	
	State();
	virtual ~State();

	virtual void updateState(Agent* pAgent);
	virtual void initialiseState(Agent* pAgent);
	virtual void exitState(Agent* pAgent);

	State* m_currentState;        
	State* m_prevState;
	State* m_nextState;
};

