/*
** Created by doom on 07/01/19.
*/

#ifndef META_SEQUENCE_CONS_HPP
#define META_SEQUENCE_CONS_HPP

#include <meta/sequence/list.hpp>

namespace meta
{
    namespace details
    {
        template <typename T, typename Sequence>
        struct cons;

        template <typename T, typename ...Types>
        struct cons<T, list<Types...>>
        {
            using type = list<T, Types...>;
        };
    }

    template <typename T, typename Sequence>
    using cons = typename details::cons<T, Sequence>::type;
}

#endif /* !META_SEQUENCE_CONS_HPP */
