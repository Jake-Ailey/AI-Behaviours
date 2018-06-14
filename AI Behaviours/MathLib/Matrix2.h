#pragma once
#include "Vector2.h"

struct Matrix2
{
	Matrix2();
	Matrix2(float m00, float m01,		//Initialising 2x2 matrix with paramater contents
			float m10, float m11);
	~Matrix2();

	Vector2 operator*(Vector2 rhs);
	Matrix2 operator*(Matrix2 rhs);

	Vector2& operator[](int index);
	explicit operator float*();

	void setRotate(float fRadians);

	void setPosition(float x, float y);
	void setPosition(Vector2 pos);

	void setScale(float x, float y);
	void setScale(Vector2 scale);

	Vector2 getPosition();

	float m[2][2];
};

