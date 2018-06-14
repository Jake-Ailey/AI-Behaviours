#pragma once
#include "Vector4.h"
#include "Vector3.h"
#include "Vector2.h"

struct Matrix4
{
	Matrix4();
	Matrix4(float m00, float m01, float m02, float m03,			//Initialising the 4x4 matrix with paramater contents
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33);
	~Matrix4();

	Vector4 operator*(Vector4 rhs);
	Matrix4 operator*(Matrix4 rhs);

	Vector4& operator[](int index);
	explicit operator float*();

	void setRotateX(float fRadians);
	void setRotateY(float fRadians);
	void setRotateZ(float fRadians);

	void setPosition(float x, float y, float z, float w);
	void setPosition(Vector4 pos);

	void setScale(float x, float y, float z, float w);
	void setScale(Vector4 scale);

	Vector4 getPosition();


	float m[4][4];
};
