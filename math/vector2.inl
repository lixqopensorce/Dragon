#include "vector2.h"

inline Vector2::Vector2() : x(0.0f), y(.0f)
{

}

inline Vector2::Vector2(float ix, float iy) : x(ix), y(iy)
{

}

inline Vector2::Vector2(const Vector2& rval) : x(rval.x), y(rval.y)
{

}

inline const Vector2& Vector2::operator=(const Vector2& rval)
{
	x = rval.x;
	y = rval.y;

	return *this;
}

inline const Vector2& Vector2::operator+=(const Vector2& rval)
{
	x += rval.x;
	y += rval.y;

	return *this;
}

inline const Vector2& Vector2::operator-=(const Vector2& rval)
{
	x -= rval.x;
	y -= rval.y;

	return *this;
}

inline const Vector2& Vector2::operator*=(float val)
{
	x *= val;
	y *= val;

	return *this;
}

inline const Vector2& Vector2::operator/=(float val)
{
	assert(fabs(val) > FLT_MIN);

	float temp = 1.0f / val;
	x *= temp;
	y *= temp;

	return *this;
}

inline const Vector2 Vector2::operator+(const Vector2& rval) const
{
	return Vector2(x + rval.x, y + rval.y);
}

inline const Vector2 Vector2::operator-(const Vector2& rval) const
{
	return Vector2(x - rval.x, y - rval.y);
}

inline const Vector2 Vector2::operator*(float val) const
{
	return Vector2(val * x, val * y);
}

inline const Vector2 Vector2::operator/(float val) const
{
	assert(fabs(fabs(val) - FLT_MIN) > FLT_MIN);
	float temp = 1.0f / val;
	return Vector2(x * temp, y * temp);
}

inline float Vector2::Length() const
{
	return sqrtf(x * x + y * y);
}

inline float Vector2::Dot(const Vector2& rval) const
{
	return x * rval.x + y * rval.y;
}

inline Vector2& Vector2::Normalize()
{
	float len = Length();
	assert(fabs(len - FLT_MIN) > FLT_MIN);

	x /= len;
	y /= len;

	return *this;
}

inline Vector2 Normalize(const Vector2& in_vec)
{
	float len = in_vec.Length();
	assert(fabs(len - FLT_MIN) > FLT_MIN);

	Vector2 unit_vec;
	unit_vec.x = in_vec.x / len;
	unit_vec.y = in_vec.y / len;

	return unit_vec;
}