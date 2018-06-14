#include "FleeBehaviour.h"
#include "Input.h"
#include "Vector2.h"
#include "Agent.h"


FleeBehaviour::FleeBehaviour()
{
}

FleeBehaviour::~FleeBehaviour()
{
}

Vector2 FleeBehaviour::update(Agent* pAgent, float deltaTime)
{
	aie::Input* pInput = aie::Input::getInstance();

	Vector2 v2MousePos; //This will create a new v2MousePos every time we update, but we want that because the mouse position is constantly changing
	

	v2MousePos.x = (float)pInput->getMouseX();
	v2MousePos.y = (float)pInput->getMouseY();

	//Seek Force
	Vector2 v2Dir =pAgent->getPosition() - v2MousePos;	//Our basic direction getting. Where we want to go MINUS where we currently are
	v2Dir.normalise();
	v2Dir = v2Dir * pAgent->getMaxSpeed();
	Vector2 v2Force = v2Dir - pAgent->getVelocity(); // Force is = to our current direction MINUS our velocity

	return v2Force;
}

