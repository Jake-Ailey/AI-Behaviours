#pragma once
#include "BaseBehaviour.h"
class SeekBehaviour : public BaseBehaviour
{
public:
	SeekBehaviour();
	~SeekBehaviour();

	Vector2 update(Agent* pAgent, float deltaTime);
};

