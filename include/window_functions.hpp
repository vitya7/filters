#pragma once

#include <cmath>

namespace filters
{
    template <class T = void>
    struct triangle;
}

namespace filters
{
    template <class T>
    struct triangle
    {
        using value_type = T;

        inline constexpr
        value_type operator () (value_type x) const
        {
            constexpr value_type zero = 0, one = 1, two = 2;

            return std::max( x * ( x < zero ? two : -two ) + one, zero );
        }
    };

    template <>
    struct triangle <void>
    {
        using value_type = void;

        template <class T>
        inline constexpr
        T operator () (T x) const
        {
            return triangle <T> {} ( x );
        }
    };
}
