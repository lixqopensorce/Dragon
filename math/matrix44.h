#pragma once
#include "common.h"
class Vector4;
class Vector3;
class Matrix44
{
public:
	union
	{
		struct  
		{
			float v00, v01, v02, v03;
			float v10, v11, v12, v13;
			float v20, v21, v22, v23;
			float v30, v31, v32, v33;
		};

		struct  
		{
			float arr[4][4];
		};
	};

	Matrix44();
	Matrix44(float iv00, float iv01, float iv02, float iv03,
		float iv10, float iv11, float iv12, float iv13,
		float iv20, float iv21, float iv22, float iv23,
		float iv30, float iv31, float iv32, float iv33);
	Matrix44(const Vector4& irow1, const Vector4& irow2, const Vector4& irow3, const Vector4& irow4);
	Matrix44(const Matrix44& rmat);

	const Matrix44& operator=(const Matrix44& irval);
	const Matrix44& operator+=(const Matrix44& irval);
	const Matrix44& operator-=(const Matrix44& irval);
	const Matrix44& operator*=(const Matrix44& irval);
	const Matrix44& operator*=(float ival);
	const Matrix44& operator/=(float ival);

	Matrix44 operator+(const Matrix44& irval) const;
	Matrix44 operator-(const Matrix44& irval) const;
	Matrix44 operator*(const Matrix44& irval) const;
	Matrix44 operator*(float ival) const;
	Matrix44 operator/(float ival) const;
};
//indentity matrix
//Remark:can become another function params
Matrix44& MatrixIdentity(Matrix44& iomat);
//translation matrix
Matrix44& MatrixTranslation(Matrix44& omat, Vector3& ivec);
Matrix44& MatrixTranslation(Matrix44& omat, float x, float y, float z);
//Rotate by x  Axis matrix(pitch)
Matrix44& MatrixRotationX(Matrix44& omat, float radian);
//Rotate by y Axis(yaw)
Matrix44& MatrixRotationY(Matrix44& omat, float radian);
//Rotate by z Axis(roll)
Matrix44& MatrixRotationZ(Matrix44& omat, float radian);
//Rotation by Euler
Matrix44& MatrixRotationYawPitchRoll(Matrix44& omat, float yaw_radian, float pitch_radian, float roll_radian);