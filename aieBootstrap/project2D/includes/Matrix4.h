#pragma once
#include "Vector4.h"

#ifdef STATIC_LIB //Using static .lib
	#define MATH_DLL
#else //Using dynamic .dll
	#ifdef DLL_EXPORT //Export .dll
		#define MATH_DLL __declspec(dllexport)
	#else //Import .dll
		#define MATH_DLL __declspec(dllimport)
	#endif
#endif

class Matrix4
{
public:
	MATH_DLL Matrix4();
	MATH_DLL ~Matrix4();

	MATH_DLL Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p);
	float m[4][4];

	MATH_DLL Matrix4 operator*(const Matrix4 rhs);
	MATH_DLL Vector4 operator*(const Vector4 rhs);
	MATH_DLL Matrix4 transpose(Matrix4 rhs);
	MATH_DLL void setRotateX(const float a);
	MATH_DLL void setRotateY(const float a);
	MATH_DLL void setRotateZ(const float a);
	MATH_DLL operator float*();
	MATH_DLL Vector4& operator[](const int a);
};