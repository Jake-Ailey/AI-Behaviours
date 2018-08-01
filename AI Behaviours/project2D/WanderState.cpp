#include "WanderState.h"
#include "SeekState.h"
#include "SeekBehaviour.h"
#include "WanderBehaviour.h"

WanderState::WanderState()
{
	m_pSeekBehaviour = new SeekBehaviour();
	m_pWanderBehaviour = new WanderBehaviour();
}


WanderState::~WanderState()
{
	delete m_pSeekBehaviour;
	delete m_pWanderBehaviour;
}


void WanderState::updateState(Agent* pAgent)
{
	pAgent->addBehaviour(m_pSeekBehaviour, 0.33f);			//This will always seek the mouse, because that is coded into the seek behaviour itself
	pAgent->addBehaviour(m_pWanderBehaviour, 0.66f);		//Adding a bit of wander to make the movement kind of sporadic
}

void WanderState::initialiseState(Agent* pAgent)
{
	pAgent->m_pStateMachine->m_currentState = this;			//Initialising the state
}

void WanderState::exitState(Agent* pAgent)
{
	pAgent->removeBehaviour(m_pSeekBehaviour);
	pAgent->removeBehaviour(m_pWanderBehaviour);
}
