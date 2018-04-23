#pragma once
#include "../common.h"
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

		float arr[4][4];
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
Matrix44& MatrixTranslation(Matrix44& omat, const Vector3& ivec);
Matrix44& MatrixTranslation(Matrix44& omat, float x, float y, float z);
//scale matrix
Matrix44& MatrixScaling(Matrix44& omat, float xscale, float yscale, float zscale);
//Rotate by x  Axis matrix(pitch)
Matrix44& MatrixRotationX(Matrix44& omat, float radian);
//Rotate by y Axis(yaw)
Matrix44& MatrixRotationY(Matrix44& omat, float radian);
//Rotate by z Axis(roll)
Matrix44& MatrixRotationZ(Matrix44& omat, float radian);
//Rotation by Euler
Matrix44& MatrixRotationYawPitchRoll(Matrix44& omat, float yaw_radian, float pitch_radian, float roll_radian);
//Rotation by Vector
Matrix44& MatrixRotationAxis(Matrix44& omat, Vector3& axis, float angle);
//LookAt viewport matrix left-handle Coordinate System
Matrix44& MatrixLookAtLH(Matrix44& omat, const Vector3& eye,  const Vector3& at, const Vector3& up);
//Returns the determinant of a matrix.
float MatrixDeterminant(const Matrix44& in_mat);
//Returns the determinant of a matrix2*2
float MatrixDeterminant22(const float a, const float b, const float c, const float d);
//Returns the determinant of a matrix3*3
float MatrixDeterminant33(const float a00, const float a01, const float a02, const float a10, const float a11, const float a12, const float a20, const float a21, const float a22);
//Rotation by Euler
Matrix44& MatrixRotationYawPitchRoll(Matrix44& omat, const Vector3& in_vec);
//Perspective project Matrix
Matrix44& MatrixPerspectiveLH(Matrix44& omat, float fov, float aspect, float near, float far);
//Perspective project Matrix
Matrix44& MatrixPerspectiveLH(Matrix44& omat, float in_left, float in_right, float in_top, float in_bottom, float in_near, float in_far);