#include "Agent.h"
#include <math.h>

Agent::Agent(aie::Texture* pTexture, Vector2 v2Pos, float fRadians) : GameObject(pTexture, v2Pos, fRadians)
{
	m_maxSpeed = 300.0f;
}

Agent::~Agent()
{
}

void Agent::update(float deltaTime)
{
	Vector2 v2TotalForce;

	for (int i = 0; i < m_BehaviourList.size(); i++)
	{
		float fMagnitude = v2TotalForce.magnitude();
		float fRemaining = m_maxSpeed - fMagnitude;

		if (fRemaining <= 0.0f)
			break;

		Vector2 v2Force = m_BehaviourList[i]->update(this, deltaTime);
		v2Force = v2Force * m_BehaviourList[i]->m_weighting;
		float fForceToAdd = v2Force.magnitude();

		if (fForceToAdd < fRemaining)
		{
			v2TotalForce = v2TotalForce + v2Force;
		}
		else
		{
			v2Force.normalise();
			v2TotalForce = v2TotalForce + v2Force * fRemaining;
		}
	}

	m_velocity = m_velocity + v2TotalForce * deltaTime;
	Vector2 v2Pos = getPosition();
	v2Pos = v2Pos + m_velocity * deltaTime;
	setPosition(v2Pos);

	if(m_velocity.magnitude() > 0)
	setFacing(m_velocity);
}

void Agent::draw(aie::Renderer2D* pRenderer)
{
	pRenderer->drawSpriteTransformed3x3(m_texture, (float*)m_transform);
}

//Function to get the direction that the agent is facing, based on the Y axis the the matrix transformation
Vector2 Agent::getFacing()
{
	Vector2 v2facing;

	v2facing.x = this->m_transform.m[1][0];
	v2facing.y = this->m_transform.m[1][1];

	return v2facing;
}

void Agent::setFacing(Vector2 facing)
{
	facing.normalise();
	m_transform.m[1][0] = facing.x;
	m_transform.m[1][1] = facing.y;

	m_transform.m[0][0] = facing.y;
	m_transform.m[0][1] = -facing.x;
}

void Agent::setVelocity(Vector2 velocity)
{
	m_velocity = velocity;
}

Vector2 Agent::getVelocity()
{
	return m_velocity;
}

float Agent::getMaxSpeed()
{
	return m_maxSpeed;
}

//Function to get the distance between the agent's position and the mouse position
float Agent::getDistanceBetween(Vector2 agentPosition, Vector2 mousePosition) 
{
	float result;

	//Distance Formula: 
	result = sqrt(pow((mousePosition.x - agentPosition.x), 2.0f) + (pow((mousePosition.y - agentPosition.y), 2.0f)));

	return result;
}

void Agent::addBehaviour(BaseBehaviour* pBehaviour, float weighting)
{

	pBehaviour->m_weighting = weighting;

	m_BehaviourList.push_back(pBehaviour);
}

void Agent::removeBehaviour(BaseBehaviour* pBehaviour)
{
	if (std::find(m_BehaviourList.begin(), m_BehaviourList.end(), pBehaviour) == m_BehaviourList.end());		//If the behaviour is IN the behaviour list (i think)
	{
		m_BehaviourList.erase(m_BehaviourList.begin());
	}
}

