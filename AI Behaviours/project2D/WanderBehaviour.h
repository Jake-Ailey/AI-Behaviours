#pragma once
#include "BaseBehaviour.h"
#include "Vector2.h"


class WanderBehaviour : public BaseBehaviour
{
public:
	WanderBehaviour();
	~WanderBehaviour();

protected:
	Vector2 circleCenter;
	Vector2 distance;
};

