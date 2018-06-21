#pragma once
#include "BaseBehaviour.h"
#include "Vector2.h"


class WanderBehaviour : public BaseBehaviour
{
public:
	WanderBehaviour();
	~WanderBehaviour();

	Vector2 update(Agent* pAgent, float deltaTime);

	Vector2 setAngle(Vector2 &vector, float angle);

	Vector2 randomVector(Vector2 vector);

protected:
	Vector2 m_circleCenter;			//The circle which will help to determine the character's random movement
	Vector2 wanderTarget{ 25.0f, 25.0f };
	float circleDistance = 50.0f;
	float m_wanderAngle = 25.0f;
};

