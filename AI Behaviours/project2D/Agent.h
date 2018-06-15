#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "BaseBehaviour.h"
#include <vector>


class Agent : public GameObject
{
public:
	Agent(aie::Texture* pTexture, Vector2 v2Pos, float fRadians);
	virtual ~Agent();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D* pRenderer);

	void setVelocity(Vector2 velocity);
	Vector2 getVelocity();
	float getMaxSpeed();

	void addBehaviour(BaseBehaviour* pBehaviour, float weighting);

protected:

	Vector2 m_velocity;
	float m_maxSpeed;
	std::vector<BaseBehaviour*> m_BehaviourList;
};
