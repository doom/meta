/*
** Created by doom on 13/01/19.
*/

#ifndef META_UTILS_PAIR_HPP
#define META_UTILS_PAIR_HPP

namespace meta
{
    template <typename T, typename U>
    struct pair
    {
        using first_type = T;
        using second_type = U;
    };
}

#endif /* !META_UTILS_PAIR_HPP */
