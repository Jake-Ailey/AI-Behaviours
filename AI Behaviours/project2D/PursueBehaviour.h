#pragma once
#include "BaseBehaviour.h"


class PursueBehaviour :	public BaseBehaviour
{
public:
	PursueBehaviour();
	~PursueBehaviour();

	Vector2 update(Agent* pAgent, float deltaTime);
};

