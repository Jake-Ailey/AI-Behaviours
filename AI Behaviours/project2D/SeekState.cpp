#include "SeekState.h"
#include "SeekBehaviour.h"
#include "WanderBehaviour.h"


SeekState::SeekState()
{
	m_pSeekBehaviour = new SeekBehaviour();
	m_pWanderBehaviour = new WanderBehaviour();
}

SeekState::~SeekState()
{
	delete m_pSeekBehaviour;
	delete m_pWanderBehaviour;
}

void SeekState::updateState(Agent* pAgent)
{
	pAgent->addBehaviour(m_pSeekBehaviour, 0.90f);			//This will always seek the mouse, because that is coded into the seek behaviour itself
	pAgent->addBehaviour(m_pWanderBehaviour, 0.10f);		//Adding a bit of wander to make the movement kind of sporadic
}

void SeekState::initialiseState(Agent* pAgent)
{
	pAgent->m_pStateMachine->m_currentState = this;			//Initialising the state
}

void SeekState::exitState(Agent* pAgent)
{
	pAgent->removeBehaviour(m_pSeekBehaviour);
	pAgent->removeBehaviour(m_pWanderBehaviour);
}
