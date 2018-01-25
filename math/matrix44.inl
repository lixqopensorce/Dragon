<<<<<<< HEAD
#include "matrix44.h"
#include "vector4.h"

inline Matrix44::Matrix44()
{
	memset(arr, 0, sizeof(arr));
}

inline Matrix44::Matrix44(float iv00, float iv01, float iv02, float iv03, float iv10, float iv11, float iv12, float iv13, float iv20, float iv21, float iv22, float iv23, float iv30, float iv31, float iv32, float iv33)
{
	v00 = iv00, v01 = iv01, v02 = iv02, v03 = iv03;
	v10 = iv10, v11 = iv11, v12 = iv12, v13 = iv13;
	v20 = iv20, v21 = iv21, v22 = iv22, v23 = iv23;
	v30 = iv30, v31 = iv31, v32 = iv32, v33 = iv33;
}

inline Matrix44::Matrix44(const Vector4& irow1, const Vector4& irow2, const Vector4& irow3, const Vector4& irow4)
{
	v00 = irow1.x, v01 = irow1.y, v02 = irow1.z, v03 = irow1.w;
	v10 = irow2.x, v11 = irow2.y, v12 = irow2.z, v13 = irow2.w;
	v20 = irow3.x, v21 = irow3.y, v22 = irow3.z, v23 = irow3.w;
	v30 = irow4.x, v31 = irow4.y, v32 = irow4.z, v33 = irow4.w;
}

inline Matrix44::Matrix44(const Matrix44& irval)
{
	memcpy(arr, irval.arr, sizeof(arr));
}

inline const Matrix44& Matrix44::operator=(const Matrix44& irval)
{
	memcpy(arr, irval.arr, sizeof(arr));
	return *this;
}

inline const Matrix44& Matrix44::operator+=(const Matrix44& irval)
{
	v00 = irval.v00, v01 = irval.v01, v02 = irval.v02, v03 = irval.v03;
	v10 = irval.v10, v11 = irval.v11, v12 = irval.v12, v13 = irval.v13;
	v20 = irval.v20, v21 = irval.v21, v22 = irval.v22, v23 = irval.v23;
	v30 = irval.v30, v31 = irval.v31, v32 = irval.v32, v33 = irval.v33;

	return *this;
}

