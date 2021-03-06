#include "GameObject.h"


GameObject::GameObject(aie::Texture* pTexture, Vector2 v2Pos, float fRadians)
{
	m_texture = pTexture;
	setPosition(v2Pos);
	setRotation(fRadians);
}


GameObject::~GameObject()
{
}

void GameObject::setPosition(Vector2 v2pos)
{
	m_transform.setPositionVec2(v2pos);
}

Vector2 GameObject::getPosition()
{
	return m_transform.getPositionVec2();		//Using the math library's functions
}

void GameObject::setRotation(float fRadians)
{
	m_rotation = fRadians;
	m_transform.setRotateZ(fRadians);
}

float GameObject::getRotation()
{
	return m_rotation;
}