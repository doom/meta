/*
** Created by doom on 08/01/19.
*/

#ifndef META_SEQUENCE_INSERT_AT_HPP
#define META_SEQUENCE_INSERT_AT_HPP

#include <meta/utils/integral_constants.hpp>
#include <meta/sequence/take.hpp>
#include <meta/sequence/join.hpp>
#include <meta/sequence/cons.hpp>

namespace meta
{
    namespace details
    {
        template <typename Index>
        struct insert_at
        {
            template <typename Sequence, typename T>
            using f = meta::join<meta::take<Sequence, Index>, meta::list<T>, meta::drop<Sequence, Index>>;
        };

        template <>
        struct insert_at<size_constant<0>>
        {
            template <typename Sequence, typename T>
            using f = meta::cons<T, Sequence>;
        };

    }

    template <typename Sequence, typename Index, typename T>
    using insert_at = typename details::insert_at<Index>::template f<Sequence, T>;
}

#endif /* !META_SEQUENCE_INSERT_AT_HPP */
