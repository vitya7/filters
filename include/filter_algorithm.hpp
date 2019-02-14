#pragma once

#include "filter.hpp"

namespace filters
{
    template <class T, class F, class OutIt>
    void generate_filter_bank_n (OutIt out, size_t n, T min_val, T max_val, F func)
    {
        T width = ( max_val - min_val ) * T(2) / T(n + 1);

        T shift = width / T(2);

        T center = min_val + shift;

        for(; n--; center += shift)
        {
            *out++ = filter { center, width, func };
        }
    }

    template <class T, class F, class OutIt>
    void generate_filter_bank (OutIt first, OutIt last, T min_val, T max_val, F func)
    {
        generate_filter_bank_n( first
                              , std::distance( first, last )
                              , std::move( min_val )
                              , std::move( max_val )
                              , std::move( func )
                              );
    }
}
