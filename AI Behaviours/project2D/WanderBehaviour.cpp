#include "WanderBehaviour.h"
#include "Input.h"
#include "Vector2.h"
#include "Agent.h"
#define _USE_MATH_DEFINES
#include <math.h>


WanderBehaviour::WanderBehaviour()
{
}


WanderBehaviour::~WanderBehaviour()
{
}

Vector2 WanderBehaviour::setAngle(Vector2 &vector, float angle)
{
	float length = vector.magnitude();

	vector.x = (cosf(angle) * length);
	vector.y = (sinf(angle) * length);	

	return vector;
}

Vector2 WanderBehaviour::randomVector(Vector2 vector)
{
	vector.x += (((float)rand() / (float)RAND_MAX) * 2) - 1;
	vector.y += (((float)rand() / (float)RAND_MAX) * 2) - 1;

	vector.normalise();

	return vector;
}


Vector2 WanderBehaviour::update(Agent* pAgent, float deltaTime)
{
	Vector2 v2wanderForce;

	float m_wanderRadius = 325.0f;
	float m_wanderDistance = 55.0f;
	float m_wanderJitter = 175.0f;	

	 wanderTarget = wanderTarget + (randomVector(v2wanderForce) * m_wanderJitter);

	wanderTarget.normalise();

	wanderTarget = wanderTarget * m_wanderRadius;

	Vector2 targetLocal = wanderTarget + Vector2(m_wanderDistance, 0) * pAgent->getFacing();

	targetLocal.normalise();

	targetLocal = targetLocal * pAgent->getMaxSpeed();
	targetLocal = targetLocal - pAgent->getVelocity();

	return targetLocal - pAgent->getPosition();
}
