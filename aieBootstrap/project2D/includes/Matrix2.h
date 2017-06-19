#pragma once
#include "Vector2.h"

#ifdef STATIC_LIB //Using static .lib
	#define MATH_DLL
#else //Using dynamic .dll
	#ifdef DLL_EXPORT //Export .dll
		#define MATH_DLL __declspec(dllexport)
	#else //Import .dll
		#define MATH_DLL __declspec(dllimport)
	#endif
#endif

class Matrix2
{
public:
	MATH_DLL Matrix2();
	MATH_DLL ~Matrix2();

	MATH_DLL Matrix2(float a, float b, float c, float d);
	float m[2][2];

	MATH_DLL Matrix2 operator*(const Matrix2 rhs);
	MATH_DLL Vector2 operator*(const Vector2 rhs);
	MATH_DLL Matrix2 operator*(float num);
	MATH_DLL Matrix2 transpose(Matrix2 rhs);
	MATH_DLL void setRotate(const float a);
	MATH_DLL operator float*();
	MATH_DLL Vector2& operator[](const int a);
	MATH_DLL void inverse();
};