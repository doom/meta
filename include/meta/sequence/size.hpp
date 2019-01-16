/*
** Created by doom on 29/11/18.
*/

#ifndef META_SEQUENCE_SIZE_HPP
#define META_SEQUENCE_SIZE_HPP

#include <meta/utils/integral_constants.hpp>
#include <meta/sequence/list.hpp>

namespace meta
{
    template <typename Sequence>
    struct size;

    template <typename ...Types>
    struct size<list<Types...>> : size_constant<sizeof...(Types)>
    {
    };

    template <typename ...Types>
    struct size<unordered_map<Types...>> : size_constant<sizeof...(Types)>
    {
    };
}

#endif /* !META_SEQUENCE_SIZE_HPP */
