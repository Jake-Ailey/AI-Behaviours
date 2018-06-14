#pragma once

struct Vector3
{
	Vector3();
	Vector3(float x, float y, float z);
	~Vector3();

	Vector3 operator + (Vector3 rhs);
	Vector3 operator + (float rhs);
	Vector3 operator += (Vector3 rhs);
	Vector3 operator += (float rhs);
		  
	Vector3 operator - (Vector3 rhs);
	Vector3 operator - (float rhs);
	Vector3 operator -= (Vector3 rhs);
	Vector3 operator -= (float rhs);
		  
	Vector3 operator * (Vector3 rhs);
	Vector3 operator * (float rhs);
	Vector3 operator *= (Vector3 rhs);
	Vector3 operator *= (float rhs);
		  
	Vector3 operator / (Vector3 rhs);
	Vector3 operator / (float rhs);
	Vector3 operator /= (Vector3 rhs);
	Vector3 operator /= (float rhs);

	float& operator[](int index);

	explicit operator float*();

	float magnitude();
	void normalise();
	float dot(Vector3 rhs);
	Vector3 cross(Vector3 rhs);

	double RadDeg(float radian);						//Convert radians to degrees
	double DegRad(float degree);						//Convert degrees to radians

	float x;
	float y;
	float z;
};

static Vector3 operator * (float lhs, Vector3 rhs)
{
	Vector3 result;

	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;

	return result;
}
