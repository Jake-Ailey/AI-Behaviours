#include "Duck.h"
#include "SeekBehaviour.h"
#include "FleeBehaviour.h"



Duck::Duck(aie::Texture* pTexture, Vector2 v2Pos, float fRadians) : Agent(pTexture, v2Pos, fRadians)
{
	m_maxSpeed = 600.0f;
	m_pSeekBehaviour = new SeekBehaviour();
	addBehaviour(m_pSeekBehaviour, 0.75f);
	m_pFleeBehaviour = new FleeBehaviour();
	addBehaviour(m_pFleeBehaviour, 0.25f);
}


Duck::~Duck()
{
	delete m_pSeekBehaviour;
	delete m_pFleeBehaviour;
}
