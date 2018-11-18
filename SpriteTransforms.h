#define OLC_PGE_APPLICATION
#include "libs/olcPixelGameEngine.h"

#include <algorithm>
#undef min
#undef max


class SpriteTransforms 
{
public:


private:
	olc::Sprite *sprCar;

	struct matrix3x3
	{
		float m[3][3];
	};

	void Identity(matrix3x3 &mat)
	{
		mat.m[0][0] = 1.0f; mat.m[1][0] = 0.0f; mat.m[2][0] = 0.0f;
		mat.m[0][1] = 0.0f; mat.m[1][1] = 1.0f; mat.m[2][1] = 0.0f;
		mat.m[0][2] = 0.0f; mat.m[1][2] = 0.0f; mat.m[2][2] = 1.0f;
	}

	void Translate(matrix3x3 &mat, float ox, float oy)
	{
		mat.m[0][0] = 1.0f; mat.m[1][0] = 0.0f; mat.m[2][0] = ox;
		mat.m[0][1] = 0.0f; mat.m[1][1] = 1.0f; mat.m[2][1] = oy;
		mat.m[0][2] = 0.0f;	mat.m[1][2] = 0.0f;	mat.m[2][2] = 1.0f;
	}

	void Rotate(matrix3x3 &mat, float fTheta)
	{
		mat.m[0][0] = cosf(fTheta);  mat.m[1][0] = sinf(fTheta); mat.m[2][0] = 0.0f;
		mat.m[0][1] = -sinf(fTheta); mat.m[1][1] = cosf(fTheta); mat.m[2][1] = 0.0f;
		mat.m[0][2] = 0.0f;			 mat.m[1][2] = 0.0f;		 mat.m[2][2] = 1.0f;
	}

	void Scale(matrix3x3 &mat, float sx, float sy)
	{
		mat.m[0][0] = sx;   mat.m[1][0] = 0.0f; mat.m[2][0] = 0.0f;
		mat.m[0][1] = 0.0f; mat.m[1][1] = sy;   mat.m[2][1] = 0.0f;
		mat.m[0][2] = 0.0f;	mat.m[1][2] = 0.0f;	mat.m[2][2] = 1.0f;
	}

	void Shear(matrix3x3 &mat, float sx, float sy)
	{
		mat.m[0][0] = 1.0f; mat.m[1][0] = sx;   mat.m[2][0] = 0.0f;
		mat.m[0][1] = sy;   mat.m[1][1] = 1.0f; mat.m[2][1] = 0.0f;
		mat.m[0][2] = 0.0f;	mat.m[1][2] = 0.0f;	mat.m[2][2] = 1.0f;
	}

	void MatrixMultiply(matrix3x3 &matResult, matrix3x3 &matA, matrix3x3 &matB)
	{
		for (int c = 0; c < 3; c++)
		{
			for (int r = 0; r < 3; r++)
			{
				matResult.m[c][r] = matA.m[0][r] * matB.m[c][0] +
					matA.m[1][r] * matB.m[c][1] +
					matA.m[2][r] * matB.m[c][2];
			}
		}
	}

	void Forward(matrix3x3 &mat, float in_x, float in_y, float &out_x, float &out_y)
	{
		out_x = in_x * mat.m[0][0] + in_y * mat.m[1][0] + mat.m[2][0];
		out_y = in_x * mat.m[0][1] + in_y * mat.m[1][1] + mat.m[2][1];
	}

	void Invert(matrix3x3 &matIn, matrix3x3 &matOut)
	{
		float det = matIn.m[0][0] * (matIn.m[1][1] * matIn.m[2][2] - matIn.m[1][2] * matIn.m[2][1]) -
			matIn.m[1][0] * (matIn.m[0][1] * matIn.m[2][2] - matIn.m[2][1] * matIn.m[0][2]) +
			matIn.m[2][0] * (matIn.m[0][1] * matIn.m[1][2] - matIn.m[1][1] * matIn.m[0][2]);

		float idet = 1.0f / det;
		matOut.m[0][0] = (matIn.m[1][1] * matIn.m[2][2] - matIn.m[1][2] * matIn.m[2][1]) * idet;
		matOut.m[1][0] = (matIn.m[2][0] * matIn.m[1][2] - matIn.m[1][0] * matIn.m[2][2]) * idet;
		matOut.m[2][0] = (matIn.m[1][0] * matIn.m[2][1] - matIn.m[2][0] * matIn.m[1][1]) * idet;
		matOut.m[0][1] = (matIn.m[2][1] * matIn.m[0][2] - matIn.m[0][1] * matIn.m[2][2]) * idet;
		matOut.m[1][1] = (matIn.m[0][0] * matIn.m[2][2] - matIn.m[2][0] * matIn.m[0][2]) * idet;
		matOut.m[2][1] = (matIn.m[0][1] * matIn.m[2][0] - matIn.m[0][0] * matIn.m[2][1]) * idet;
		matOut.m[0][2] = (matIn.m[0][1] * matIn.m[1][2] - matIn.m[0][2] * matIn.m[1][1]) * idet;
		matOut.m[1][2] = (matIn.m[0][2] * matIn.m[1][0] - matIn.m[0][0] * matIn.m[1][2]) * idet;
		matOut.m[2][2] = (matIn.m[0][0] * matIn.m[1][1] - matIn.m[0][1] * matIn.m[1][0]) * idet;
	}
};
