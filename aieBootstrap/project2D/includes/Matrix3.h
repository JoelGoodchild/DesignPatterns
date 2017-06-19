#pragma once
#include "Vector3.h"

#ifdef STATIC_LIB //Using static .lib
	#define MATH_DLL
#else //Using dynamic .dll
	#ifdef DLL_EXPORT //Export .dll
		#define MATH_DLL __declspec(dllexport)
	#else //Import .dll
		#define MATH_DLL __declspec(dllimport)
	#endif
#endif

class Matrix3
{
public:
	MATH_DLL Matrix3();
	MATH_DLL ~Matrix3();

	MATH_DLL Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i);
	float m[3][3];

	MATH_DLL Matrix3 operator*(const Matrix3 rhs);
	MATH_DLL Vector3 operator*(const Vector3 rhs);
	MATH_DLL Matrix3 operator*(float num);
	MATH_DLL Matrix3 transpose(Matrix3 rhs);
	MATH_DLL void setRotateX(const float a);
	MATH_DLL void setRotateY(const float a);
	MATH_DLL void setRotateZ(const float a);
	MATH_DLL operator float*();
	MATH_DLL Vector3& operator[](const int a);
	MATH_DLL void inverse();
};