#pragma once

#include "mel_hz_utility.hpp"

namespace filters
{
    template <class T>
    struct hz
    {
        using value_type = T;

        constexpr inline
        hz (value_type value = value_type{})
            : value { value }
        {}

        template <class Tp>
        constexpr inline
        hz (mel <Tp> const& x)
            : value { mel_to_hz( x.value ) }
        {}

        constexpr inline
        operator value_type () const
        {
            return value;
        }

        value_type value;
    };

    template <class Tp> hz (mel <Tp>) -> hz <Tp>;
}
