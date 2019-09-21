/*
** Created by doom on 16/01/19.
*/

#ifndef META_UTILS_PRIORITY_TAG_HPP
#define META_UTILS_PRIORITY_TAG_HPP

#include <cstddef>

namespace doom::meta
{
    template <std::size_t I>
    struct priority_tag : priority_tag<I - 1>
    {
    };

    template <>
    struct priority_tag<0>
    {
    };
}

#endif /* !META_UTILS_PRIORITY_TAG_HPP */
