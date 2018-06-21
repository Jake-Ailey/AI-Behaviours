#include "Duck.h"
#include "SeekBehaviour.h"
#include "FleeBehaviour.h"
#include "WanderBehaviour.h"


Duck::Duck(aie::Texture* pTexture, Vector2 v2Pos, float fRadians) : Agent(pTexture, v2Pos, fRadians)
{
	m_maxSpeed = 600.0f;
	m_pSeekBehaviour = new SeekBehaviour();
	addBehaviour(m_pSeekBehaviour, 0.33f);
	m_pFleeBehaviour = new FleeBehaviour();
	//addBehaviour(m_pFleeBehaviour, 0.5f);
	m_pWanderBehaviour = new WanderBehaviour();
	addBehaviour(m_pWanderBehaviour, 0.66f);
}


Duck::~Duck()
{
	delete m_pSeekBehaviour;
	delete m_pFleeBehaviour;
	delete m_pWanderBehaviour;
}
