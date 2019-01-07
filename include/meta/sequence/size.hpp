/*
** Created by doom on 29/11/18.
*/

#ifndef META_SEQUENCE_SIZE_HPP
#define META_SEQUENCE_SIZE_HPP

#include <cstddef>
#include <type_traits>
#include <meta/sequence/list.hpp>

namespace meta
{
    template <typename Sequence>
    struct size;

    template <typename ...Types>
    struct size<list<Types...>> : std::integral_constant<std::size_t, sizeof...(Types)>
    {
    };
}

#endif /* !META_SEQUENCE_SIZE_HPP */
