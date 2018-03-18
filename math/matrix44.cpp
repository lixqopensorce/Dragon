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



 