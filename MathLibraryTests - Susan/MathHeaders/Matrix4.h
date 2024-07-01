#pragma once
namespace MathClasses
{
    struct Matrix4
    {
      
        public:
            union {
                struct {
                    float m1, m2, m3, m4;
                    float m5, m6, m7, m8;
                    float m9, m10, m11, m12;
                    float m13, m14, m15, m16;
                };
                float mm[4][4];
            };

            // Default constructor
            Matrix4()
                : m1(0), m2(0), m3(0), m4(0),
                m5(0), m6(0), m7(0), m8(0),
                m9(0), m10(0), m11(0), m12(0),
                m13(0), m14(0), m15(0), m16(0) {}

            // Parameterized constructor (individual elements)
            Matrix4(float m1, float m2, float m3, float m4,
                float m5, float m6, float m7, float m8,
                float m9, float m10, float m11, float m12,
                float m13, float m14, float m15, float m16)
                : m1(m1), m2(m2), m3(m3), m4(m4),
                m5(m5), m6(m6), m7(m7), m8(m8),
                m9(m9), m10(m10), m11(m11), m12(m12),
                m13(m13), m14(m14), m15(m15), m16(m16) {}

            // Parameterized constructor (array)
            Matrix4(const float* elements)
            {
                for (int i = 0; i < 16; ++i)
                    ((float*)this)[i] = elements[i];
            }

            // Matrix multiplication (Matrix4 * Vector4)
            Vector4 operator*(const Vector4& vec) const
            {
                return Vector4(
                    m1 * vec.x + m2 * vec.y + m3 * vec.z + m4 * vec.w,
                    m5 * vec.x + m6 * vec.y + m7 * vec.z + m8 * vec.w,
                    m9 * vec.x + m10 * vec.y + m11 * vec.z + m12 * vec.w,
                    m13 * vec.x + m14 * vec.y + m15 * vec.z + m16 * vec.w
                );
            }

            // Matrix multiplication (Matrix4 * Matrix4)
            Matrix4 operator*(const Matrix4& other) const
            {
                Matrix4 result;
                for (int row = 0; row < 4; ++row)
                {
                    for (int col = 0; col < 4; ++col)
                    {
                        result.mm[row][col] =
                            mm[row][0] * other.mm[0][col] +
                            mm[row][1] * other.mm[1][col] +
                            mm[row][2] * other.mm[2][col] +
                            mm[row][3] * other.mm[3][col];
                    }
                }
                return result;
            }

            // Subscript operator
            float& operator[](int index)
            {
                return ((float*)this)[index];
            }

            // Subscript operator (const)
            const float& operator[](int index) const
            {
                return ((const float*)this)[index];
            }

            // Make identity matrix
            static Matrix4 MakeIdentity()
            {
                return Matrix4(
                    1, 0, 0, 0,
                    0, 1, 0, 0,
                    0, 0, 1, 0,
                    0, 0, 0, 1
                );
            }

            // Cast to float*
            operator float* () { return &m1; }
            operator const float* () const { return &m1; }
	};
}