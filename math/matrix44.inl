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

inline Matrix44 Matrix44::operator+(const Matrix44& irval) const
{
	Matrix44 out_mat;
	out_mat.v00 = v00 + irval.v00, out_mat.v01 = v01 + irval.v01;
	out_mat.v02 = v02 + irval.v02, out_mat.v03 = v03 + irval.v03;
	out_mat.v10 = v10 + irval.v10, out_mat.v11 = v11 + irval.v11;
	out_mat.v12 = v12 + irval.v12, out_mat.v13 = v13 + irval.v13;
	out_mat.v20 = v20 + irval.v20, out_mat.v21 = v21 + irval.v21;
	out_mat.v22 = v22 + irval.v22, out_mat.v23 = v23 + irval.v23;
	out_mat.v30 = v30 + irval.v30, out_mat.v31 = v31 + irval.v31;
	out_mat.v32 = v32 + irval.v32, out_mat.v33 = v33 + irval.v33;

	return out_mat;
}

inline Matrix44 Matrix44::operator-(const Matrix44& irval) const
{
	Matrix44 out_mat;
	for (int irow = 0; irow < 4; ++irow)
	{
		for (int icol = 0; icol < 4; ++icol)
		{
			out_mat.arr[irow][icol] = arr[irow][icol] - irval.arr[irow][icol];
		}
	}

	return out_mat;
}

inline Matrix44 Matrix44::operator*(float ival) const
{
	Matrix44 out_mat;
	for (int irow = 0; irow < 4; ++irow)
	{
		for (int icol = 0; icol < 4; ++icol)
		{
			out_mat.arr[irow][icol] = arr[irow][icol] * ival;
		}
	}

	return out_mat;
}

inline Matrix44 Matrix44::operator*(const Matrix44& irval) const
{
	Matrix44 out_mat;
	for (int irow = 0; irow < 4; ++irow)
	{
		for (int icol = 0; icol < 4; ++icol)
		{
			out_mat.arr[irow][icol] = arr[irow][0] * irval[0][icol] + arr[irow][1] * irval.arr[1][icol] + arr[irow][2] * irval.arr[2][icol] + arr[irow][3] * irval.arr[3][icol];
		}
	}

	return out_mat;
}

inline Matrix44 Matrix44::operator/(float ival) const
{
	assert(ival != 0);
	ival = 1.0f / ival;
	Matrix44 out_mat;
	for (int irow = 0; irow < 4; ++irow)
	{
		for (int icol = 0; icol < 4; ++icol)
		{
			out_mat.arr[irow][icol] = arr[irow][icol] * ival;
		}
	}

	return out_mat;
}

inline const Matrix44& Matrix44::operator+=(const Matrix44& irval)
{
	*this = *this + irval;

	return *this;
}

inline const Matrix44& Matrix44::operator-=(const Matrix44& irval)
{
	*this = *this - irval;

	return *this;
}

inline const Matrix44& Matrix44::operator*=(const Matrix44& irval)
{
	*this = *this * irval;

	return *this;
}

inline const Matrix44& Matrix44::operator*=(float ival)
{
	*this = *this * ival;
		
	return *this;
}

inline const Matrix44& Matrix44::operator/=(float ival)
{
	*this = *this / ival;

	return *this;
}
