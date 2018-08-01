#pragma once
#include "State.h"

class FleeBehaviour;

class FleeState : public State
{
public:
	FleeState();
	~FleeState();

	void updateState(Agent* pAgent);			//Updates the state every frame
	void initialiseState(Agent* pAgent);		//Initialises the state at the start of runtime
	void exitState(Agent* pAgent);				//Function to exit a given state

	FleeBehaviour* m_pFleeBehaviour;
};

