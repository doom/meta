/*
** Created by doom on 17/01/19.
*/

#ifndef META_SEQUENCE_FROM_LIST_HPP
#define META_SEQUENCE_FROM_LIST_HPP

#include <meta/sequence/list.hpp>
#include <meta/sequence/unordered_map.hpp>

namespace meta
{
    namespace details
    {
        template <template <typename ...> typename T, typename List>
        struct from_list;

        template <template <typename ...> typename T, typename ...Types>
        struct from_list<T, meta::list<Types...>>
        {
            using type = T<Types...>;
        };
    }

    template <template <typename ...> typename T, typename List>
    using from_list = typename details::from_list<T, List>::type;
}

#endif /* !META_SEQUENCE_FROM_LIST_HPP */
