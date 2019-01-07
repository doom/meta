/*
** Created by doom on 29/11/18.
*/

#ifndef META_SEQUENCE_FILTER_HPP
#define META_SEQUENCE_FILTER_HPP

#include <type_traits>
#include <meta/sequence/list.hpp>
#include <meta/sequence/map.hpp>
#include <meta/sequence/flatten.hpp>

namespace meta
{
    namespace details
    {
        template <template <typename ...> typename Pred>
        struct list_or_empty
        {
            template <typename ...Types>
            using f = std::conditional_t<Pred<Types...>::value, list<Types...>, list<>>;
        };
    }

    /**
     * Filter the elements of a sequence based on a predicate
     */
    template <template <typename ...> typename MetaF, typename Sequence>
    using filter = flatten<map<details::list_or_empty<MetaF>::template f, Sequence>>;
}

#endif /* !META_SEQUENCE_FILTER_HPP */
