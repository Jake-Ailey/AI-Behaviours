#include "WanderBehaviour.h"
#include "Input.h"
#include "Vector2.h"
#include "Agent.h"
#define _USE_MATH_DEFINES
#include <math.h>


WanderBehaviour::WanderBehaviour()
{
	m_displacement = m_displacement * circleDistance;
	
}


WanderBehaviour::~WanderBehaviour()
{
}

void WanderBehaviour::setAngle(Vector2 vector, float angle)
{
	float length = vector.magnitude();

	vector.x = cosf(angle) * length;
	vector.y = sinf(angle) * length;
}

Vector2 WanderBehaviour::update(Agent* pAgent, float deltaTime)
{
	float randomNum = rand() % 2;
	Vector2 v2Force;

	m_circleCenter = pAgent->getVelocity();
	m_circleCenter.normalise();
	m_circleCenter = m_circleCenter * circleDistance;

	m_displacement = m_displacement * M_PI_2;

	setAngle(m_displacement, m_wanderAngle);

	m_wanderAngle = (m_wanderAngle * randomNum) - (randomNum * 0.5);

	v2Force = m_circleCenter + m_displacement;

	return v2Force;
}
