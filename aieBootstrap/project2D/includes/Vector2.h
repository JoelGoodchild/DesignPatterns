#pragma once

#ifdef STATIC_LIB //Using static .lib
	#define MATH_DLL
#else //Using dynamic .dll
	#ifdef DLL_EXPORT //Export .dll
		#define MATH_DLL __declspec(dllexport)
	#else //Import .dll
		#define MATH_DLL __declspec(dllimport)
	#endif
#endif

class Vector2
{
public:
	MATH_DLL Vector2();
	MATH_DLL Vector2(float x, float y);
	MATH_DLL ~Vector2();

	MATH_DLL Vector2 operator+(const Vector2& rhs);
	MATH_DLL Vector2 operator-(const Vector2& rhs);
	MATH_DLL Vector2 operator*(const float rhs);
	MATH_DLL Vector2 operator/(const float rhs);
	MATH_DLL Vector2 operator-();
	MATH_DLL float dot(Vector2 rhs);
	MATH_DLL float magnitude();
	MATH_DLL float sqrMagnitude();
	MATH_DLL float magnitude(Vector2 rhs);
	MATH_DLL float sqrMagnitude(Vector2 rhs);
	MATH_DLL void normalise();
	MATH_DLL float& operator[](const int a);
	MATH_DLL operator float*();
	MATH_DLL bool operator>(const Vector2& rhs);
	MATH_DLL bool operator<(const Vector2& rhs);
	MATH_DLL bool operator==(const Vector2& rhs);
	MATH_DLL bool operator!=(const Vector2& rhs);
	MATH_DLL bool operator<=(const Vector2& rhs);
	MATH_DLL bool operator>=(const Vector2& rhs);

	MATH_DLL Vector2 xx();
	MATH_DLL Vector2 xy();
	MATH_DLL Vector2 yx();
	MATH_DLL Vector2 yy();

	float x;
	float y;
};

MATH_DLL Vector2 operator*(float lhs, const Vector2 rhs);