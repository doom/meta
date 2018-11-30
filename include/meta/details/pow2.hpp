/*
** Created by doom on 31/10/18.
*/

#ifndef META_POW2_HPP
#define META_POW2_HPP

#include <cstddef>

namespace meta::details
{
    /**
     * Get the exponent needed to obtain a power of two greater than the given number
     */
    inline constexpr size_t next_pow2(size_t n) noexcept
    {
        if (n > 128)
            return 8;
        if (n > 64)
            return 7;
        if (n > 32)
            return 6;
        if (n > 16)
            return 5;
        if (n > 8)
            return 4;
        if (n > 4)
            return 3;
        if (n > 2)
            return 2;
        if (n > 1)
            return 1;
        return 0;
    }
}

#endif /* !META_POW2_HPP */
