#pragma once

#include "common.h"

class Vector4
{
public:
	Vector4();
	Vector4(float ix, float iy, float iz, float iw);
	Vector4(const Vector4& rval);

	const Vector4& operator=(const Vector4& rval);
	const Vector4& operator+=(const Vector4& rval);
	const Vector4& operator-=(const Vector4& rval);
	const Vector4& operator*=(float val);
	const Vector4& operator/=(float val);

	const Vector4 operator+(const Vector4& rval) const;
	const Vector4 operator-(const Vector4& rval) const;
	const Vector4 operator*(float val) const;
	const Vector4 operator/(float val) const;

	const Vector4& Homegenize();
	float Length() const;
	float Dot(const Vector4& rval) const;
	const Vector4& Normalize();

	float x;
	float y;
	float z;
	float w;
};