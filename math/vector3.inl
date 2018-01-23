#include "vector3.h"

inline Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f)
{}

inline Vector3::Vector3(float ix, float iy, float iz) : x(ix), y(iy), z(iz)
{

}

inline Vector3::Vector3(const Vector3& rval) : x(rval.x), y(rval.y), z(rval.z)
{
	
}

inline const Vector3& Vector3::operator=(const Vector3& rval)
{
	if (this == &rval)
	{
		return *this;
	}

	x = rval.x;
	y = rval.y;
	z = rval.z;
}

inline const Vector3& Vector3::operator+=(const Vector3& rval)
{
	x += rval.x;
	y += rval.y;
	z += rval.z;

	return *this;
}

inline const Vector3& Vector3::operator*=(float val)
{
	x *= val;
	y *= val;
	z *= val;

	return *this;
}

inline const Vector3& Vector3::operator/=(float val)
{
	assert(fabs(val) > FLT_MIN);

	x /= val;
	y /= val;
	z /= val;

	return *this;
}

inline const Vector3 Vector3::operator+(const Vector3& rval) const
{
	return Vector3(x + rval.x, y + rval.y, z + rval.z);
}

inline const Vector3 Vector3::operator-(const Vector3& rval) const
{
	return Vector3(x - rval.x, y - rval.y, z - rval.z);
}

inline const Vector3 Vector3::operator*(float val) const
{
	return Vector3(x * val, y *val, z * val);
}

inline const Vector3 Vector3::operator/(float val) const
{
	assert(fabs(val) > FLT_MIN);
	return Vector3(x / val, y / val, z / val);
}

inline float Vector3::Length() const
{
	return sqrtf(x * x + y * y + z * z);
}

inline float Vector3::Dot(const Vector3& rval) const
{
	return x * rval.x + y * rval.y + z * rval.z;
}

inline const Vector3& Vector3::Normalize()
{
	float len = Length();
	assert(len > FLT_MIN);

	*this /= len;
	return *this;
}

inline const Vector3 Vector3::Cross(const Vector3& rval) const
{
	Vector3 ret_vec;
	ret_vec.x = y * rval.z - z * rval.y;
	ret_vec.y = x * rval.z - z * rval.x;
	ret_vec.z = x * rval.y - y * rval.x;

	return ret_vec;
}
