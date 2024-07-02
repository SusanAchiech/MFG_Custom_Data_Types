#ifndef MATRIX3_H
#define MATRIX3_H
#pragma once
namespace MathClasses
{
    struct Matrix3
    {
        public:
    // Matrix elements
    float m1, m2, m3;
    float m4, m5, m6;
    float m7, m8, m9;

    // Default constructor
    Matrix3() :
        m1(0), m2(0), m3(0),
        m4(0), m5(0), m6(0),
        m7(0), m8(0), m9(0) {}

    // Parameterized constructor (individual floats)
    Matrix3(float m1, float m2, float m3,
            float m4, float m5, float m6,
            float m7, float m8, float m9) :
        m1(m1), m2(m2), m3(m3),
        m4(m4), m5(m5), m6(m6),
        m7(m7), m8(m8), m9(m9) {}

    // Parameterized constructor (array)
    Matrix3(const float elements[9]) :
        m1(elements[0]), m2(elements[1]), m3(elements[2]),
        m4(elements[3]), m5(elements[4]), m6(elements[5]),
        m7(elements[6]), m8(elements[7]), m9(elements[8]) {}

    // Operator overload for matrix multiplication
    Matrix3 operator*(const Matrix3& other) const {
        return Matrix3(
            m1 * other.m1 + m2 * other.m4 + m3 * other.m7,
            m1 * other.m2 + m2 * other.m5 + m3 * other.m8,
            m1 * other.m3 + m2 * other.m6 + m3 * other.m9,

            m4 * other.m1 + m5 * other.m4 + m6 * other.m7,
            m4 * other.m2 + m5 * other.m5 + m6 * other.m8,
            m4 * other.m3 + m5 * other.m6 + m6 * other.m9,

            m7 * other.m1 + m8 * other.m4 + m9 * other.m7,
            m7 * other.m2 + m8 * other.m5 + m9 * other.m8,
            m7 * other.m3 + m8 * other.m6 + m9 * other.m9
        );
    }

    // Operator overload for matrix-vector multiplication
    Vector3 operator*(const Vector3& vec) const {
        return Vector3(
            m1 * vec.x + m2 * vec.y + m3 * vec.z,
            m4 * vec.x + m5 * vec.y + m6 * vec.z,
            m7 * vec.x + m8 * vec.y + m9 * vec.z
        );
    }

    // Make identity matrix
    static Matrix3 MakeIdentity() {
        return Matrix3(
            1.f, 0.f, 0.f,
            0.f, 1.f, 0.f,
            0.f, 0.f, 1.f
        );
    }

    // Transpose matrix
    Matrix3 Transposed() const {
        return Matrix3(
            m1, m4, m7,
            m2, m5, m8,
            m3, m6, m9
        );
    }

    // Subscript operator
    float& operator[](int index) {
        return *((&m1) + index);
    }

    const float& operator[](int index) const {
        return *((&m1) + index);
    }

    // Cast to float pointer
    operator float*() {
        return &m1;
    }

    operator const float*() const {
        return &m1;
    }
	};
}
#endif