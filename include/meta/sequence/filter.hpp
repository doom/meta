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
        template <template <typename> typename Pred>
        struct list_or_empty
        {
            template <typename T>
            using f = std::conditional_t<Pred<T>::value, list<T>, list<>>;
        };

        template <template <typename> typename MetaF, typename Sequence>
        struct filter
        {
            using type = meta::flatten<meta::map<list_or_empty<MetaF>::template f, Sequence>>;
        };
    }

    /**
     * Filter the elements of a sequence based on a predicate
     */
    template <template <typename> typename MetaF, typename Sequence>
    using filter = typename details::filter<MetaF, Sequence>::type;
}

#endif /* !META_SEQUENCE_FILTER_HPP */
