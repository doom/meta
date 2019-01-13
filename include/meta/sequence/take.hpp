/*
** Created by doom on 02/01/19.
*/

#ifndef META_SEQUENCE_TAKE_HPP
#define META_SEQUENCE_TAKE_HPP

#include <cstddef>
#include <meta/sequence/drop.hpp>
#include <meta/sequence/rotate.hpp>
#include <meta/sequence/size.hpp>

namespace meta
{
    namespace details
    {
        template <bool>
        struct take
        {
            template <typename Sequence, typename N>
            using f = meta::drop<meta::rotate<Sequence, N>, size_constant<size<Sequence>::value - N::value>>;
        };

        template <>
        struct take<false>
        {
            template <typename Sequence, typename>
            using f = Sequence;
        };
    }

    template <typename Sequence, typename N>
    using take = typename details::take<(size<Sequence>::value > N::value)>::template f<Sequence, N>;
}

#endif /* !META_SEQUENCE_TAKE_HPP */
