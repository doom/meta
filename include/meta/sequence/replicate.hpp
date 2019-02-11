/*
** Created by doom on 10/02/19.
*/

#ifndef META_SEQUENCE_REPLICATE_HPP
#define META_SEQUENCE_REPLICATE_HPP

#include <utility>
#include <meta/sequence/list.hpp>

namespace meta
{
    namespace details
    {
        template <typename IndexSeq, typename T>
        struct replicate_helper;

        template <std::size_t ...Is, typename T>
        struct replicate_helper<std::index_sequence<Is...>, T>
        {
            template <std::size_t>
            using ignore_and_t = T;

            using type = meta::list<ignore_and_t<Is>...>;
        };
    }

    template <typename N, typename T>
    using replicate = typename details::replicate_helper<std::make_index_sequence<N::value>, T>::type;
}

#endif /* !META_SEQUENCE_REPLICATE_HPP */
