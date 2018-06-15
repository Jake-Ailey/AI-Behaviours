#pragma once
#include "BaseBehaviour.h"
#include "Vector2.h"


class WanderBehaviour : public BaseBehaviour
{
public:
	WanderBehaviour();
	~WanderBehaviour();

	Vector2 update(Agent* pAgent, float deltaTime);

	void setAngle(Vector2 vector, float angle);

protected:
	Vector2 m_circleCenter;			//The circle which will help to determine the character's random movement
	float circleDistance = 5.0f;

	Vector2 m_displacement{0, -1};
	float m_wanderAngle = 5.0f;
};

