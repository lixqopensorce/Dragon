#include "vector4.h"

inline Vector4::Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
{}

inline Vector4::Vector4(float ix, float iy, float iz, float iw) : x(ix), y(iy), z(iz), w(iw)
{}

inline Vector4::Vector4(const Vector4& rval) : x(rval.x), y(rval.y), z(rval.z), w(rval.w)
{
}

inline const Vector4& Vector4::operator=(const Vector4& rval)
{
	x = rval.x;
	y = rval.y;
	z = rval.z;
	w = rval.w;

	return *this;
}

inline const Vector4& Vector4::operator+=(const Vector4& rval)
{
	x += rval.x;
	y += rval.y;
	z += rval.z;
	w += rval.w;

	return *this;
}

inline const Vector4& Vector4::operator-=(const Vector4& rval)
{
	x -= rval.x;
	y -= rval.y;
	z -= rval.z;
	w -= rval.w;
}

inline const Vector4& Vector4::operator*=(float val)
{
	x *= val;
	y *= val;
	z *= val;
	w *= val;

	return *this;
}

inline const Vector4& Vector4::operator/=(float val)
{
	assert(fabs(fabs(val) - FLT_MIN) > FLT_MIN);

	x /= val;
	y /= val;
	z /= val;
	w /= val;

	return *this;
}

inline const Vector4 Vector4::operator+(const Vector4& rval) const
{
	Vector4 ret_vec;
	ret_vec += rval;

	return ret_vec;
}

inline const Vector4 Vector4::operator-(const Vector4& rval) const
{
	Vector4 ret_vec;
	ret_vec -= rval;

	return ret_vec;
}

inline const Vector4 Vector4::operator*(float val) const
{
	Vector4 ret_vec;
	ret_vec *= val;

	return ret_vec;
}

inline const Vector4 Vector4::operator/(float val) const
{
	Vector4 ret_vec;
	ret_vec /= val;

	return ret_vec;
}

inline float Vector4::Length() const
{
	return sqrtf(x * x + y * y + z * z + w * w);
}

inline float Vector4::Dot(const Vector4& rval) const
{
	return x * rval.x + y * rval.y + z * rval.z + w * rval.w;
}

inline const Vector4& Vector4::Homegenize()
{
	assert(w != 0);

	float val = 1.0f / w;
	*this *= val;
	return *this;
}

inline Vector4& Vector4::Normalize()
{
	float len = Length();
	assert(fabs(len - FLT_MIN) > FLT_MIN);
	float val = 1.0f / Length();

	*this *= val;
	return *this;
}

inline Vector4 Normalize(const Vector4& in_vec)
{
	float len = in_vec.Length();
	assert(fabs(len - FLT_MIN) > FLT_MIN);

	float val = 1.0f / len;

	Vector4 unit_vec;
	unit_vec = in_vec * val;

	return unit_vec;
}