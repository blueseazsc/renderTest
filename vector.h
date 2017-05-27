#ifndef VECTOR_H
#define VECTOR_H

#include "config.h"
#include <math.h>
#include <vector>
namespace framework {
class Vector3 {
public:
	Vector3() : x(0.f), y(0.f), z(0.f) {}
	Vector3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
	Vector3(const Vector3& vec) : x(vec.x), y(vec.y), z(vec.z) {}
	const Vector3& operator = (const Vector3& vec) { x = vec.x; y = vec.y; z = vec.z; return *this; }

	const Vector3& operator += (const Vector3& vec) { x += vec.x; y += vec.y; z += vec.z; return *this; }
	const Vector3& operator -= (const Vector3& vec) { x -= vec.x; y -= vec.y; z -= vec.z; return *this; }
	const Vector3& operator *= (float f) { x *= f; y *= f; z *= f; return *this; }
	const Vector3& operator /= (float f) { f = 1.f / f; x *= f; y *= f; z *= f; return *this; }

	Vector3 operator + () const { return *this; }
	Vector3 operator - () const { return Vector3(-x,-y,-z); }

	void Clear() { x = y = z = 0.f; }
	bool IsZero() const { return x == 0.f && y == 0.f && z == 0.f; }

	float Modulus() const { return (float)(sqrt(x*x + y*y + z*z)); }
	float SquareModulus() const { return x*x + y*y + z*z; }
	float HorizontalSquModulus() const { return x*x + z*z; }

	inline float SquDistance( const Vector3& vec ) const {
		float dis_x = x-vec.x;
		float dis_y = y-vec.y;
		float dis_z = z-vec.z;
		return dis_x*dis_x + dis_y*dis_y + dis_z*dis_z;
	}
	inline float Distance( const Vector3& vec ) const {
		return sqrt(SquDistance(vec));
	}
	inline float HorizontalSquDistance( const Vector3& vec ) const {
		float dis_x = x-vec.x;
		float dis_z = z-vec.z;
		return dis_x*dis_x + dis_z*dis_z;
	}
	inline float HorizontalDistance( const Vector3& vec ) const {
		return sqrt(HorizontalSquDistance(vec));
	}

	float Normalize() {
		float mod = Modulus();
		if ( ::IsZero(mod) )
		{
			Clear();
			mod = 0.f;
		}
		else
		{
			float f = 1.0f / mod;
			x = x * f;
			y = y * f;
			z = z * f;
		}

		return mod;
	}
public:
	float x, y, z;
};

bool operator == (const Vector3& vec1, const Vector3& vec2);
bool operator != (const Vector3& vec1, const Vector3& vec2);

Vector3 operator + (const Vector3& vec1, const Vector3& vec2);
Vector3 operator - (const Vector3& vec1, const Vector3& vec2);

Vector3 operator * (const Vector3& vec, float f);
Vector3 operator * (const Vector3& vec, int32_t f);

Vector3 operator / (const Vector3& vec, float f);
Vector3 operator / (const Vector3& vec, int32_t f);
Vector3 operator / (const Vector3& vec1, const Vector3& vec2);

float DotProduct(const Vector3& vec1, const Vector3& vec2);
Vector3 CrossProduct(const Vector3& vec1, const Vector3& vec2);

typedef std::vector<Vector3> PointVec;
}
#endif
