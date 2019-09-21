/*
** Created by doom on 29/11/18.
*/

#ifndef META_SEQUENCE_CONCAT_HPP
#define META_SEQUENCE_CONCAT_HPP

#include <meta/sequence/list.hpp>

namespace doom::meta
{
    namespace details
    {
        template <typename List, typename OtherList>
        struct concat;

        template <typename ...Types, typename ...OtherTypes>
        struct concat<list<Types...>, list<OtherTypes...>>
        {
            using type = list<Types..., OtherTypes...>;
        };
    }

    /**
     * Concatenate two sequences
     */
    template <typename Sequence, typename OtherSequence>
    using concat = typename details::concat<Sequence, OtherSequence>::type;
}

#endif /* !META_SEQUENCE_CONCAT_HPP */
