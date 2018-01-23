#pragma once

#include "common.h"

class Vector3
{
public:
	Vector3();
	Vector3(float ix, float iy, float iz);
	Vector3(const Vector3& rval);
	
	const Vector3& operator=(const Vector3& rval);
	const Vector3& operator+=(const Vector3& rval);
	const Vector3& operator-=(const Vector3& rval);
	const Vector3& operator*=(float val);
	const Vector3& operator/=(float val);

	const Vector3 operator+(const Vector3& rval) const;
	const Vector3 operator-(const Vector3& rval) const;
	const Vector3 operator*(float val) const;
	const Vector3 operator/(float val) const;

	float Length() const;
	float Dot(const Vector3& rval) const;
	const Vector3 Cross(const Vector3& rval) const;
	const Vector3& Normalize();

	float x;
	float y;
	float z;
};

#include "vector3.inl"