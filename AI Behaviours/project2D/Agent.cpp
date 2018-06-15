#include "Agent.h"


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
}

void Agent::draw(aie::Renderer2D* pRenderer)
{
	pRenderer->drawSpriteTransformed3x3(m_texture, (float*)m_transform);
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

void Agent::addBehaviour(BaseBehaviour* pBehaviour, float weighting)
{

	pBehaviour->m_weighting = weighting;

	m_BehaviourList.push_back(pBehaviour);
}