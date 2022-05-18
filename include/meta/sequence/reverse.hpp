/*
** Created by doom on 19/05/22.
*/

#ifndef META_SEQUENCE_REVERSE_HPP
#define META_SEQUENCE_REVERSE_HPP

#include <utility>
#include <tuple>

#include <meta/sequence/list.hpp>

namespace doom::meta
{
    namespace details
    {
        template <typename Sequence>
        struct reverse;

        template <typename ...Ts>
        struct reverse<list<Ts...>>
        {
            template <std::size_t ...Is>
            static auto func(std::index_sequence<Is...>)
            {
                return list<std::remove_reference_t<decltype(std::get<sizeof...(Ts) - Is - 1>(std::declval<std::tuple<Ts...>>()))>...>{};
            }

            using type = decltype(func(std::make_index_sequence<sizeof...(Ts)>{}));
        };
    }

    template <typename Sequence>
    using reverse = typename details::reverse<Sequence>::type;
}

#endif /* !META_SEQUENCE_REVERSE_HPP */
