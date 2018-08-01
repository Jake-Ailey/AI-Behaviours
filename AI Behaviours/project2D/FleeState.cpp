#include "FleeState.h"
#include "FleeBehaviour.h"

FleeState::FleeState()
{
	m_pFleeBehaviour = new FleeBehaviour();
}

FleeState::~FleeState()
{
	delete m_pFleeBehaviour;
}

void FleeState::updateState(Agent* pAgent)
{
	pAgent->addBehaviour(m_pFleeBehaviour, 1.0f);		//This will always seek the mouse, because that is coded into the seek behaviour itself
}

void FleeState::initialiseState(Agent* pAgent)
{
	pAgent->addBehaviour(m_pFleeBehaviour, 1.0f);		//Initialising the state
}

void FleeState::exitState(Agent* pAgent)
{
	pAgent->removeBehaviour(m_pFleeBehaviour);
}
