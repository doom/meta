/*
** Created by doom on 20/01/19.
*/

#ifndef META_SEQUENCE_DROP_AT_HPP
#define META_SEQUENCE_DROP_AT_HPP

#include <meta/sequence/take.hpp>
#include <meta/sequence/drop.hpp>
#include <meta/sequence/concat.hpp>
#include <meta/sequence/list.hpp>

namespace meta
{
    namespace details
    {
        template <typename Sequence, typename Index>
        struct drop_at;

        template <typename ...Types, typename Index>
        struct drop_at<meta::list<Types...>, Index>
        {
            using type = meta::concat<
                meta::take<meta::list<Types...>, Index>,
                meta::drop<meta::list<Types...>, meta::plus<Index, size_constant<1>>>
            >;
        };
    }

    template <typename Sequence, typename Index>
    using drop_at = typename details::drop_at<Sequence, Index>::type;
}

#endif /* !META_SEQUENCE_DROP_AT_HPP */
