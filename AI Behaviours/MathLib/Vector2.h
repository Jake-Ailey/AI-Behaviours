#pragma once

struct Vector2
{
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	Vector2 operator + (Vector2 rhs);
	Vector2 operator + (float rhs);
	Vector2 operator += (Vector2 rhs);
	Vector2 operator += (float rhs);

	Vector2 operator - (Vector2 rhs);
	Vector2 operator - (float rhs);
	Vector2 operator -= (Vector2 rhs);
	Vector2 operator -= (float rhs);

	Vector2 operator * (Vector2 rhs);
	Vector2 operator * (float rhs);
	Vector2 operator *= (Vector2 rhs);
	Vector2 operator *= (float rhs);

	Vector2 operator / (Vector2 rhs);
	Vector2 operator / (float rhs);
	Vector2 operator /= (Vector2 rhs);
	Vector2 operator /= (float rhs);

	float& operator[](int index);

	explicit operator float*();

	float magnitude();
	void normalise();
	float dot(Vector2 rhs);
	double angle(Vector2 rhs);

	double RadDeg(float radian);						//Convert radians to degrees
	double DegRad(float degree);						//Convert degrees to radians

	float x;
	float y;	
};

static Vector2 operator * (float lhs, Vector2 rhs)
{
	Vector2 result;

	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;

	return result;
}