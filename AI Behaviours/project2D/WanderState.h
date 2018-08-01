#pragma once
#include "State.h"

class SeekBehaviour;
class WanderBehaviour;

class WanderState : public State
{
public:
	WanderState();
	~WanderState();

	void updateState(Agent* pAgent);			//Updates the state every frame
	void initialiseState(Agent* pAgent);		//Initialises the state at the start of runtime
	void exitState(Agent* pAgent);				//Function to exit a given state

	SeekBehaviour* m_pSeekBehaviour;
	WanderBehaviour* m_pWanderBehaviour;
};

