#pragma once
class Agent;
class Vector2;

class BaseBehaviour
{
public:
	BaseBehaviour();
	virtual ~BaseBehaviour();

	virtual Vector2 update(Agent* pAgent, float deltatime) = 0;

	float m_weighting;
};

