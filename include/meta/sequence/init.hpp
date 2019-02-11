/*
** Created by doom on 10/02/19.
*/

#ifndef META_SEQUENCE_INIT_HPP
#define META_SEQUENCE_INIT_HPP

#include <meta/sequence/take.hpp>
#include <meta/sequence/size.hpp>
#include <meta/utils/integral_constants.hpp>

namespace meta
{
    namespace details
    {
        template <typename Sequence>
        struct init_helper
        {
            static_assert(meta::size<Sequence>::value > 0, "meta::init: the list should not be empty");

            using type = meta::take<
                Sequence,
                size_constant<meta::size<Sequence>::value - 1>
            >;
        };
    }

    template <typename Sequence>
    using init = typename details::init_helper<Sequence>::type;
}

#endif /* !META_SEQUENCE_INIT_HPP */
