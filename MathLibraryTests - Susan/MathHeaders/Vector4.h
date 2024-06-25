#pragma once
#include <string>

namespace MathClasses
{
    struct Vector4
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        // ...

         // Data fields representing the 4 components of the vector
        float x, y, z, w;

        //adding constructors
        Vector4();
        // Default constructor initializing all components to 0
        Vector4(float x4d, float y4d, float z4d, float w4d);

        //subtraction
        Vector4 operator-(const Vector4& rhs) const;
        // Subtraction assignment operator updating the vector by subtracting another vector
        Vector4& operator-=(const Vector4& rhs);

        //addition
        Vector4 operator+(const Vector4& rhs) const;
        // Addition assignment operator updating the vector by adding another vector
        Vector4& operator+=(const Vector4& rhs);

        //vector scalar division
        Vector4 operator/(float scalar) const;
        Vector4 operator/=(float scalar);

        //vector scalar multiplication
        Vector4 operator*(float scalar) const;
        Vector4 operator*=(float scalar);
        friend Vector4 operator*(float scalar, const Vector4& lhs);

        // Calculating and returning the magnitude (length) of the vector
        float Magnitude() const;

        // Calculating and returning the squared magnitude (length) of the vector
        float MagnitudeSqr() const;

        // Function to normalize the vector (make its magnitude 1)
        void Normalise();
        // Function to return a normalized copy of the vector (leaving the original vector unchanged)
        Vector4 Normalised() const;

        // Function to calculate and return the distance between this vector and another vector
        float Distance(const Vector4& other) const;

        // Calculating and returning the dot product of this vector and another vector
        float Dot(const Vector4& other) const;

        // Calculating and returning the cross product of this vector and another vector
        Vector4 Cross(const Vector4& other) const;

        // Comparing if two vectors are equal or not equal
        bool operator==(const Vector4 rhs) const;
        bool operator!=(const Vector4 rhs)const;

        // Converting the vector to a string representation
        std::string ToString() const;
	};
}