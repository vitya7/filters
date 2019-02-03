#pragma once

#include "mel_hz_utility.hpp"

namespace filters
{
    template <class T>
    struct hz
    {
        using value_type = T;

        constexpr inline
        hz (value_type value = value_type{}) noexcept
            : value { value }
        {}

        template <class Tp>
        constexpr inline
        hz (hz <Tp> const& x)
            : value { x.value }
        {}

        template <class Tp>
        constexpr inline
        hz (mel <Tp> const& x)
            : value { mel_to_hz( x.value ) }
        {}

        constexpr inline
        operator value_type () const noexcept
        {
            return value;
        }

        constexpr inline
        operator value_type & () & noexcept
        {
            return value;
        }

        value_type value;
    };

    template <class Tp> hz (hz <Tp> const&) -> hz <Tp>;
    template <class Tp> hz (mel <Tp> const&) -> hz <Tp>;
}
