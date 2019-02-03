#pragma once

#include "mel_hz_utility.hpp"

namespace filters
{
    template <class T>
    struct mel
    {
        using value_type = T;

        constexpr inline
        mel (value_type value = value_type{}) noexcept
            : value { value }
        {}

        template <class Tp>
        constexpr inline
        mel (mel <Tp> const& x)
            : value { x.value }
        {}

        template <class Tp>
        constexpr inline
        mel (hz <Tp> const& x)
            : value { hz_to_mel( x.value ) }
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

    template <class Tp> mel (mel <Tp> const&) -> mel <Tp>;
    template <class Tp> mel (hz <Tp> const&) -> mel <Tp>;
}
