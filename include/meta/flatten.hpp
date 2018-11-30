/*
** Created by doom on 29/11/18.
*/

#ifndef META_FLATTEN_HPP
#define META_FLATTEN_HPP

#include <meta/details/pow2.hpp>
#include <meta/details/flatten_helper.hpp>
#include <meta/list.hpp>

namespace meta
{
    namespace details
    {
        template <typename List>
        struct flatten;

        template <typename ...ContainedLists>
        struct flatten<list<ContainedLists...>>
        {
            using type = typename details::flatten_helper<details::next_pow2(
                sizeof...(ContainedLists))>::template f<ContainedLists...>::type;
        };
    }

    /**
     * Flatten a sequence of sequences (e.g. list<list<A>, list<B>, list<C> -> list<A, B, C>)
     */
    template <typename Sequence>
    using flatten = typename details::flatten<Sequence>::type;
}

#endif /* !META_FLATTEN_HPP */
