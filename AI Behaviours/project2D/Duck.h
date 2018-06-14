#pragma once
#include "Agent.h"

class SeekBehaviour;
class FleeBehaviour;

class Duck : public Agent
{
public:
	Duck(aie::Texture* pTexture, Vector2 v2Pos, float fRadians);
	~Duck();

private:
	SeekBehaviour* m_pSeekBehaviour;
	FleeBehaviour* m_pFleeBehaviour;
};

