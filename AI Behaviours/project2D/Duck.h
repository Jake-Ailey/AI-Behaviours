#pragma once
#include "Agent.h"

class SeekBehaviour;
class FleeBehaviour;
class WanderBehaviour;
class SeekState;
class FleeState;
class WanderState;

class Duck : public Agent
{
public:
	Duck(aie::Texture* pTexture, Vector2 v2Pos, float fRadians);
	~Duck();

	void update(Vector2 v2mousePos, float deltaTime);

private:
	SeekBehaviour* m_pSeekBehaviour;
	FleeBehaviour* m_pFleeBehaviour;
	WanderBehaviour* m_pWanderBehaviour;

	SeekState* m_pSeekState;
	FleeState* m_pFleeState;
	WanderState* m_pWanderState;
};

