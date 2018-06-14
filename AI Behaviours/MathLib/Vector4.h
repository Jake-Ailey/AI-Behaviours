#pragma once

struct Vector4
{
	Vector4();
	Vector4(float x, float y, float z, float w);
	~Vector4();

	Vector4 operator + (Vector4 rhs);
	Vector4 operator + (float rhs);
		  
	Vector4 operator - (Vector4 rhs);
	Vector4 operator - (float rhs);
		  
	Vector4 operator * (Vector4 rhs);
	Vector4 operator * (float rhs);
		  
	Vector4 operator / (Vector4 rhs);
	Vector4 operator / (float rhs);

	float& operator[](int index);

	explicit operator float*();

	float magnitude();
	void normalise();
	float dot(Vector4 rhs);
	Vector4 cross(Vector4 rhs);

	double RadDeg(float radian);						//Convert radians to degrees
	double DegRad(float degree);						//Convert degrees to radians

	float x;
	float y;
	float z;
	float w;
};

static Vector4 operator * (float lhs, Vector4 rhs)
{
	Vector4 result;

	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;

	return result;
}