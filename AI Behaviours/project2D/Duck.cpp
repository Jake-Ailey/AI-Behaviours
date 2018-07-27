#include "Duck.h"
#include "SeekBehaviour.h"
#include "FleeBehaviour.h"
#include "WanderBehaviour.h"
#include "StateMachine.h"
#include "SeekState.h"
#include "FleeState.h"
#include "WanderState.h"


Duck::Duck(aie::Texture* pTexture, Vector2 v2Pos, float fRadians) : Agent(pTexture, v2Pos, fRadians)
{
	m_maxSpeed = 600.0f;

	m_pStateMachine = new StateMachine;

	m_pSeekState = new SeekState;
	m_pFleeState = new FleeState;
	m_pWanderState = new WanderState;

	m_pSeekState->initialiseState(this);
}

Duck::~Duck()
{
	delete m_pStateMachine;
	delete m_pSeekState;
	delete m_pFleeState;
}

void Duck::update(Vector2 v2mousePos, float deltaTime)
{
	Agent::update(deltaTime);

	float distance = getDistanceBetween(this->getPosition(), v2mousePos);

	if (distance < 50.0f)
	{
		this->m_pStateMachine->changeState(m_pFleeState);
	}

	if (distance > 50.0f && distance < 150.0f)
	{
		this->m_pStateMachine->changeState(m_pWanderState);
	}

	else if (distance > 150.0f)
	{
		this->m_pStateMachine->changeState(m_pSeekState);
	}

	m_pStateMachine->update(this);
}
