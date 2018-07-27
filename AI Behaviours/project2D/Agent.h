#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "StateMachine.h"
#include "BaseBehaviour.h"
#include <vector>


class Agent : public GameObject
{
public:
	Agent(aie::Texture* pTexture, Vector2 v2Pos, float fRadians);
	virtual ~Agent();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D* pRenderer);

	Vector2 getFacing();
	void setFacing(Vector2 facing);

	void setVelocity(Vector2 velocity);
	Vector2 getVelocity();
	float getMaxSpeed();
	float getDistanceBetween(Vector2 agentPosition, Vector2 mousePosition);			//Distance check between Duck and mouse

	void addBehaviour(BaseBehaviour* pBehaviour, float weighting);
	void removeBehaviour(BaseBehaviour* pBehaviour);

	StateMachine* m_pStateMachine;

protected:

	Vector2 m_velocity;
	float m_maxSpeed;
	std::vector<BaseBehaviour*> m_BehaviourList;
};

