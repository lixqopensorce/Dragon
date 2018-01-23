#pragma once

#include "common.h"

class Vector2
{
public:
	Vector2();
	Vector2(const Vector2& rval);
	Vector2(float ix, float iy);

	const Vector2& operator=(const Vector2& rh);
	const Vector2& operator+=(const Vector2& rh);
	const Vector2& operator-=(const Vector2& rh);
	const Vector2& operator*=(float val);
	const Vector2& operator/=(float val);

	const Vector2 operator+(const Vector2& rh) const;
	const Vector2 operator-(const Vector2& rh) const;
	const Vector2 operator*(float val) const;
	const Vector2 operator/(float val) const;

	float Length() const;
	float Dot(const Vector2& rh) const;
	const Vector2& Normalize();

	float x;
	float y;
};

#include "vector2.inl"
