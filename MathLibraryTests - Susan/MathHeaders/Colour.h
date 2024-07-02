#ifndef COLOUR_H
#define COLOUR_H
#pragma once

#include <UnitTestLib.h>
namespace MathClasses
{
    struct Colour
    {
    public:
        UnitLib::Colour colour;

        // Default constructor
        Colour() : colour(UnitLib::BuildColour(0, 0, 0, 255)) {}

        // Parameterized constructor
        Colour(UnitLib::Byte r, UnitLib::Byte g, UnitLib::Byte b, UnitLib::Byte a) :
            colour(UnitLib::BuildColour(r, g, b, a)) {}

        // Equality operator
        bool operator==(const Colour& other) const {
            return colour == other.colour;
        }

        // Set red component
        void SetRed(UnitLib::Byte r) {
            colour = UnitLib::BuildColour(r, GetGreen(), GetBlue(), GetAlpha());
        }

        // Set green component
        void SetGreen(UnitLib::Byte g) {
            colour = UnitLib::BuildColour(GetRed(), g, GetBlue(), GetAlpha());
        }

    };
}
#endif