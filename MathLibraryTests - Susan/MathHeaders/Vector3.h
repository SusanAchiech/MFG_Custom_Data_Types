#ifndef VECTOR3_H
#define VECTOR3_H
#pragma once
#include <string>
#include <cmath>

namespace MathClasses
{
    struct Vector3
    {
        float x, y, z;

        //constructors
        Vector3(): x(0), y(0), z(0) {}
        Vector3(float x, float y, float z ) : x(x), y(y), z(z) {}

        //Ewuality operator
        bool operator==(const Vector3& other) const
        {
            return x == other.x && y == other.y && z == other.z;
        }

        //Additional operator
        Vector3 operator+(const Vector3& other) const
        {
            return Vector3(x + other.x, y + other.y, z + other.z);
        }

        // Scalar multiplication
        Vector3 operator*(float scalar) const
        {
            return Vector3(x * scalar, y * scalar, z * scalar);
        }

        //Dot product
        float Dot(const Vector3 & other) const
        {
            return x * other.x + y * other.y + z * other.z;      
        }

        //Cross  product
        Vector3 Cross(const Vector3& other) const
        {
            return Vector3(
                y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x
            );
        }

        // Magnitude
        float Magnitude() const
        {
            return sqrt(x * x + y * y + z * z);
        }

        //Normalize
        Vector3 Normalize() const
        {
            float mag = Magnitude();
            if (mag == 0) return Vector3();
            return Vector3(x / mag, y / mag, z / mag);
        }
	};
}

#endif // VECTOR3_H