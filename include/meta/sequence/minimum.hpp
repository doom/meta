/*
** Created by doom on 24/01/19.
*/

#ifndef META_SEQUENCE_MIN_HPP
#define META_SEQUENCE_MIN_HPP

#include <cstddef>
#include <meta/sequence/foldl.hpp>
#include <meta/sequence/head.hpp>
#include <meta/sequence/tail.hpp>
#include <meta/sequence/size.hpp>
#include <meta/utils/meta_functions.hpp>

namespace meta
{
    namespace details
    {
        template <template <typename, typename> typename IsLess, typename Sequence, std::size_t Size>
        struct minimum
        {
            template <typename A, typename B>
            using least = meta::if_<IsLess<A, B>, A, B>;

            using type = meta::foldl<least, meta::head<Sequence>, meta::tail<Sequence>>;
        };

        template <template <typename, typename> typename IsLess, typename Sequence>
        struct minimum<IsLess, Sequence, 1>
        {
            using type = meta::head<Sequence>;
        };
    }

    template <template <typename, typename> typename IsLess, typename Sequence>
    using minimum = typename details::minimum<IsLess, Sequence, size<Sequence>::value>::type;
}

#endif /* !META_SEQUENCE_MIN_HPP */
