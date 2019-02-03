#pragma once

#include <cmath>

namespace filters
{
    template <class T>
    inline constexpr
    T hz_to_mel (T x)
    {
        return T(2595.0) * std::log10( T(1.0) + x / T(700.0) );
    }

    template <class T>
    inline constexpr
    T mel_to_hz (T x)
    {
        return T(700.0) * std::exp( x / T(1127.0) - T(1.0) );
    }
}

namespace filters
{
    template <class T = double> struct hz;
    template <class T = double> struct mel;
}

#include "hz.hpp"
#include "mel.hpp"
