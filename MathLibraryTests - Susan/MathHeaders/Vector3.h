#pragma once
#include <string>

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
        bool operator+(const Vector3& other) const
        {
            return Vector3(x + other.x, y + other.y, z + other.z);
        }

        // Scalar multiplication

	};
}