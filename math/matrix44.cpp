#include "matrix44.h"
#include "vector3.h"

Matrix44& MatrixIdentity(Matrix44& iomat)
{
	for (int irow = 0; irow < 4; ++irow)
	{
		for (int icol = 0; icol < 4; ++icol)
		{
			if (irow == icol)
			{
				iomat[irow][icol] == 1.0f;
			}
			else
			{
				iomat[irow][icol] = 0;
			}
		}
	}

	return iomat;
}

Matrix44& MatrixTranslation(Matrix44& omat, float x, float y, float z)
{
	MatrixIdentity(omat);

	omat.arr[3][0] = x;
	omat.arr[3][1] = y;
	omat.arr[3][2] = z;

	return omat;
}

Matrix44& MatrixTranslation(Matrix44& omat, Vector3& ivec)
{
	MatrixTranslation(omat, ivec.x, ivec.y, ivec.z);

	return omat;
}

Matrix44& MatrixScaling(Matrix44& omat, float xscale, float yscale, float zscale)
{
	MatrixIdentity(omat);

	omat.arr[0][0] = xscale;
	omat.arr[1][1] = yscale;
	omat.arr[2][2] = zscale;

	return omat;
}

Matrix44& MatrixRotationX(Matrix44& omat, float radian)
{
	MatrixIdentity(omat);

	float fsin = sinf(radian);
	float fcos = cosf(radian);
	omat.arr[1][1] = fcos;
	omat.arr[2][1] = -fsin;
	omat.arr[1][2] = fsin;
	omat.arr[2][2] = fcos;

	return omat;
}

Matrix44& MatrixRotationY(Matrix44& omat, float radian)
{
	MatrixIdentity(omat);

	float fsin = sinf(radian);
	float fcos = cosf(radian);
	omat.arr[0][0] = fcos;
	omat.arr[2][0] = -fsin;
	omat.arr[0][2] = fsin;
	omat.arr[2][2] = fcos;

	return omat;
}

Matrix44& MatrixRotationZ(Matrix44& omat, float radian)
{
	MatrixIdentity(omat);

	float fsin = sinf(radian);
	float fcos = cosf(radian);
	omat.arr[0][0] = fcos;
	omat.arr[1][0] = -fsin;
	omat.arr[0][1] = fsin;
	omat.arr[1][1] = fcos;

	return omat;
}

//yaw pitch roll
Matrix44& MatrixRotationYawPitchRoll(Matrix44& omat, float yaw_radian, float pitch_radian, float roll_radian)
{
	MatrixIdentity(omat);

	Matrix44 yawmat, pitchmat, rollmat;
	MatrixRotationY(yawmat, yaw_radian);
	MatrixRotationX(pitchmat, pitch_radian);
	MatrixRotationZ(rollmat, roll_radian);

	omat = yawmat * pitchmat * rollmat;

	return omat;
}

Matrix44& MatrixRotationAxis(Matrix44& omat, Vector3& axis, float angle)
{
	MatrixIdentity(omat);
	axis.Normalize();

	float f_cos = cosf(angle);
	float f_sin = sinf(angle);

	float xqrt = axis.x * axis.x;
	float xyvalue = axis.x * axis.y;
	float yqrt = axis.y * axis.y;
	float other_cos = 1 - f_cos;

	omat.arr[0][0] = xqrt * other_cos + f_cos;
	omat.arr[0][1] = xyvalue * other_cos + axis.x * f_sin;
	omat.arr[0][2] = xqrt * other_cos - axis.y * f_sin;

	omat.arr[1][0] = xyvalue * other_cos - axis.x * f_sin;
	omat.arr[1][1] = yqrt * other_cos + f_cos;
	omat.arr[1][2] = xyvalue * other_cos + axis.x * f_sin;

	omat.arr[2][0] = xqrt * other_cos + axis.y * f_sin;
	omat.arr[2][1] = xyvalue * other_cos - axis.x * f_sin;
	omat.arr[2][2] = xqrt * other_cos + f_cos;

	return omat;
}

Matrix44& MatrixRotationYawPitchRoll(Matrix44& omat, const Vector3& in_vec)
{
	return MatrixRotationYawPitchRoll(omat, in_vec.x, in_vec.y, in_vec.z);
}

Matrix44& MatrixLookAtLH(Matrix44& omat, const Vector3& eye, const Vector3& at, const Vector3& up)
{
	MatrixIdentity(omat);
	//z-axis
	Vector3 z_axis = (at - eye).Normalize();
	//x-axis
	Vector3 x_axis = up.Cross(z_axis);
	//y-axis
	Vector3 y_axis = z_axis.Cross(x_axis);
	
	Vector3 translation_vec = Vector3(eye.Dot(x_axis), eye.Dot(y_axis), eye.Dot(z_axis));

	omat.arr[0][0] = x_axis.x;
	omat.arr[1][0] = x_axis.y;
	omat.arr[2][0] = x_axis.z;
	omat.arr[3][0] = -eye.Dot(x_axis);

	omat.arr[0][1] = y_axis.x;
	omat.arr[1][1] = y_axis.y;
	omat.arr[2][1] = y_axis.z;
	omat.arr[3][1] = -eye.Dot(y_axis);

	omat.arr[0][2] = z_axis.x;
	omat.arr[1][2] = z_axis.y;
	omat.arr[2][2] = z_axis.z;
	omat.arr[2][3] = -eye.Dot(z_axis);

	return omat;
}

float MatrixDeterminant(const Matrix44& in_mat)
{
	float ftemp1 = in_mat.arr[0][0] * MatrixDeterminant33(in_mat.arr[1][1], in_mat.arr[1][2], in_mat.arr[1][3], in_mat.arr[2][1], in_mat.arr[2][2], in_mat.arr[2][3],
		in_mat.arr[3][1], in_mat.arr[3][2], in_mat.arr[3][3]);
	float ftemp2 = -1 * in_mat.arr[0][1] * MatrixDeterminant33(in_mat.arr[1][0], in_mat.arr[1][2], in_mat.arr[1][3], in_mat.arr[2][0], in_mat.arr[2][2], in_mat.arr[2][3],
		in_mat.arr[3][0], in_mat.arr[3][2], in_mat.arr[3][3]);
	float ftemp3 = in_mat.arr[0][2] * MatrixDeterminant33(in_mat.arr[1][0], in_mat.arr[1][1], in_mat.arr[1][3], in_mat.arr[2][0], in_mat.arr[2][1], in_mat.arr[2][3],
		in_mat.arr[3][0], in_mat.arr[3][1], in_mat.arr[3][3]);
	float ftemp4 = -1 * in_mat.arr[0][3] * MatrixDeterminant33(in_mat.arr[1][0], in_mat.arr[1][1], in_mat.arr[1][2], in_mat.arr[2][0], in_mat.arr[2][1], in_mat.arr[2][2],
		in_mat.arr[3][0], in_mat.arr[3][1], in_mat.arr[3][2]);
	
	return ftemp1 + ftemp2 + ftemp3 + ftemp4;
}

//ÐÐÁÐÊ½
float MatrixDeterminant22(const float a, const float b, const float c, const float d)
{
	return a * d - b * c;
}

float MatrixDeterminant33(const float a00, const float a01, const float a02, const float a10, const float a11, const float a12, const float a20, const float a21, const float a22)
{
	return a00 * MatrixDeterminant22(a11, a12, a21, a22) - a01 * MatrixDeterminant22(a10, a12, a20, a22) + a02 * MatrixDeterminant22(a10, a11, a20, a21);
}
 