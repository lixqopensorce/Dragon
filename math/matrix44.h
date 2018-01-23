#pragma once
#include "common.h"
class Vector4;
class Vector3;
class Matrix44
{
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

	const Matrix44& operator=(const Matrix44& irval);
	const Matrix44& operator+=(const Matrix44& irval);
	const Matrix44& operator-=(const Matrix44& irval);
	const Matrix44& operator*=(const Matrix44& irval);
	const Matrix44& operator*=(float ival);
	const Matrix44& operator/=(float ival);
};
//indentity matrix
const Matrix44& matIndentity(Matrix44 iomat);
//translation matrix
const Matrix44& matTranslation(Matrix44& omat, Vector3& ivec);
//Rotate by x  Axis matrix(pitch)
const Matrix44& matRotationX(Matrix44& omat, float radian);
//Rotate by y Axis(yaw)
const Matrix44& matRotationY(Matrix44& omat, float radian);
//Rotate by z Axis(roll)
const Matrix44& matRotationZ(Matrix44& omat, float radian);
//Rotation by Euler
const Matrix44& matRotationYawPitchRoll(Matrix44& omat, const Vector3& iradians);
//Rotation by Euler
const Matrix44& matRotationYawPitchRoll(Matrix44& omat, float yaw_radian, float pitch_radian, float roll_radian);