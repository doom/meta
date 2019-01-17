/*
** Created by doom on 29/11/18.
*/

#ifndef META_SEQUENCE_MAP_HPP
#define META_SEQUENCE_MAP_HPP

#include <meta/sequence/list.hpp>

namespace meta
{
    namespace details
    {
        template <template <typename> typename MetaF, typename Sequence>
        struct map;

        template <template <typename> typename MetaF, typename ...Types>
        struct map<MetaF, list<Types...>>
        {
            using type = list<MetaF<Types>...>;
        };
    }

    /**
     * Apply a metafunction to each element of a sequence
     */
    template <template <typename> typename MetaF, typename Sequence>
    using map = typename details::map<MetaF, Sequence>::type;
}

#endif /* !META_SEQUENCE_MAP_HPP */
