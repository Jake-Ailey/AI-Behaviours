#pragma once
#include "BaseBehaviour.h"
class FleeBehaviour : public BaseBehaviour
{
public:
	FleeBehaviour();
	~FleeBehaviour();

	Vector2 update(Agent* pAgent, float deltaTime);
};

