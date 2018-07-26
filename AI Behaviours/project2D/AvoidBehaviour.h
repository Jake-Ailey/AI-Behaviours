#pragma once
#include "BaseBehaviour.h"
class AvoidBehaviour :
	public BaseBehaviour
{
public:
	AvoidBehaviour();
	~AvoidBehaviour();

	Vector2 update(Agent* pAgent, float deltaTime);


};

