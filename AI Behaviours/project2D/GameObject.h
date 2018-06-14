#pragma once
#include "Renderer2D.h"
#include "Texture.h"
#include "Vector2.h"
#include "Matrix3.h"

//YOU WILL NEED TO INCLUDE MATH LIBRARY FOR THIS TO WORK
class GameObject
{
public:
	GameObject(aie::Texture* pTexture, Vector2 v2Pos, float fRadians);
	virtual ~GameObject();

	virtual void update(float deltaTime) = 0;
	virtual void draw(aie::Renderer2D* pRenderer) = 0;

	void setPosition(Vector2 v2pos);
	Vector2 getPosition();

	void setRotation(float fRadians);
	float getRotation();
	

protected:
	Matrix3 m_transform;
	aie::Texture* m_texture;
	float m_rotation;

	Vector2 v2Position;

};

