#include "vector.h"

namespace framework {

bool operator == (const Vector3& vec1, const Vector3& vec2) { return vec1.x==vec2.x && vec1.y==vec2.y && vec1.z==vec2.z; }
bool operator != (const Vector3& vec1, const Vector3& vec2) { return vec1.x!=vec2.x || vec1.y!=vec2.y || vec1.z!=vec2.z; }

Vector3 operator + (const Vector3& vec1, const Vector3& vec2) { return Vector3(vec1.x+vec2.x, vec1.y+vec2.y, vec1.z+vec2.z); }
Vector3 operator - (const Vector3& vec1, const Vector3& vec2) { return Vector3(vec1.x-vec2.x, vec1.y-vec2.y, vec1.z-vec2.z); }

Vector3 operator * (const Vector3& vec, float f) { return Vector3(vec.x*f, vec.y*f, vec.z*f); }
Vector3 operator * (const Vector3& vec, int f) { return vec * (float)f; }

Vector3 operator / (const Vector3& vec, float f) { f = 1.f / f; return Vector3(vec.x*f, vec.y*f, vec.z*f); }
Vector3 operator / (const Vector3& vec, int f) { return vec / (float)f; }
Vector3 operator / (const Vector3& vec1, const Vector3& vec2) { return Vector3(vec1.x/vec2.x, vec1.y/vec2.y, vec1.z/vec2.z); }

float DotProduct(const Vector3& vec1, const Vector3& vec2) {
	return vec1.x*vec2.x + vec1.y*vec2.y + vec1.z*vec2.z;
}
Vector3 CrossProduct(const Vector3& vec1, const Vector3& vec2) {
	return Vector3(vec1.y * vec2.z - vec1.z * vec2.y,
			vec1.z * vec2.x - vec1.x * vec2.z,
			vec1.x * vec2.y - vec1.y * vec2.x);
}

}
