#include "PursueBehaviour.h"
#include "Input.h"
#include "Vector2.h"
#include "Agent.h"



PursueBehaviour::PursueBehaviour()
{
}


PursueBehaviour::~PursueBehaviour()
{
}

Vector2 PursueBehaviour::update(Agent* pAgent, float deltaTime)
{
	aie::Input* pInput = aie::Input::getInstance();

	Vector2 v2MousePos; //This will create a new v2MousePos every time we update, but we want that because the mouse position is constantly changing

	v2MousePos.x = (float)pInput->getMouseX();
	v2MousePos.y = (float)pInput->getMouseY();

	//Pursue Force


	return v2MousePos;
}
