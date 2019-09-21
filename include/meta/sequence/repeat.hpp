/*
** Created by doom on 20/01/19.
*/

#ifndef META_SEQUENCE_REPEAT_HPP
#define META_SEQUENCE_REPEAT_HPP

#include <utility>
#include <meta/sequence/list.hpp>

namespace doom::meta
{
    namespace details
    {
        template <typename IndexSeq>
        struct repeat_helper;

        template <std::size_t ...Is>
        struct repeat_helper<std::index_sequence<Is...>>
        {
            template <typename T, std::size_t>
            using x = T;

            template <typename T>
            using type = meta::list<x<T, Is>...>;
        };
    }

    template <typename T, typename N>
    using repeat = typename details::repeat_helper<std::make_index_sequence<N::value>>::template type<T>;
}

#endif /* !META_SEQUENCE_REPEAT_HPP */
