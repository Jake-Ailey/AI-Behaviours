#include "StateMachine.h"
#include "State.h"
#include "Agent.h"

StateMachine::StateMachine()
{
}

StateMachine::~StateMachine()
{
}

void StateMachine::update(Agent* pAgent)
{
	m_currentState->updateState(pAgent);

	if (m_nextState != nullptr)					//Makes sure that there is another state in the queue, otherwise keeps using the same state
	{
		m_currentState->exitState(pAgent);
		m_nextState->initialiseState(pAgent);	//Creating the next state
		m_prevState = m_currentState;			//Shifting everything in the "array"
		m_currentState = m_nextState;
		m_nextState = nullptr;
	}
}

void StateMachine::changeState(State* pNewState)
{
	m_nextState = pNewState;
}