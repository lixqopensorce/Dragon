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

Matrix44& MatrixRotationYawPitchRoll(Matrix44& omat, const Vector3& in_vec)
{
	return MatrixRotationYawPitchRoll(omat, in_vec.x, in_vec.y, in_vec.z);
}

Matrix44& MatrixRotationAxis(Matrix44& omat, const Vector3& axis, float angle)
{
	MatrixIdentity(omat);
	float fcos = cosf(angle);
	float fsin = sinf(angle);

	omat.arr[0][0] = axis.x * axis.x * (1 - fcos) + fcos;
	omat.arr[0][1] = axis.x * axis.y * (1 - fcos) + axis.z * fsin;
	omat.arr[0][2] = axis.x * axis.z * (1 - fcos) - axis.y * fsin;

	omat.arr[1][0] = axis.x * axis.y * (1 - fcos) - axis.x * fsin;
	omat.arr[1][1] = axis.y * axis.y * (1 - fcos) + fcos;
	omat.arr[1][2] = axis.y * axis.z * (1 - fcos) + axis.x * fsin;

	omat.arr[2][0] = axis.x * axis.z * (1 - fcos) + axis.y * fsin;
	omat.arr[2][1] = axis.y * axis.z * (1 - fcos) - axis.x * fsin;
	omat.arr[2][2] = axis.z * axis.z * (1 - fcos) + fcos;

	return omat;
}

Matrix44& MatrixLookAtLH(Matrix44& omat, Vector3& eye, Vector3& at, Vector3& up)
{
	MatrixIdentity(omat);
	Vector3 y_axis = up.Normalize();
	Vector3 x_axis = (at - eye);
	x_axis = x_axis.Normalize();
	Vector3 z_axis = x_axis.Cross(y_axis);

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



 