/*
** Created by doom on 29/11/18.
*/

#ifndef META_SEQUENCE_AT_HPP
#define META_SEQUENCE_AT_HPP

#include <utility>
#include <meta/sequence/list.hpp>

namespace meta
{
    namespace details
    {
        template <std::size_t I, typename T>
        struct indexed_element
        {
        };

        template <typename IndexSeqR, typename ...Types>
        struct indexed_list;

        template <std::size_t ...Idx, typename ...Types>
        struct indexed_list<std::index_sequence<Idx...>, Types...> : indexed_element<Idx, Types>...
        {
        };

        template <std::size_t I, typename List>
        struct at;

        template <std::size_t I, typename ...Types>
        struct at<I, list<Types...>>
        {
            static_assert(I < sizeof...(Types), "meta::at: index out of range");

            template <typename T>
            static T get(indexed_element<I, T>);

            using index_type = indexed_list<std::make_index_sequence<sizeof...(Types)>, Types...>;
            using type = decltype(at::get(index_type{}));
        };
    }

    /**
     * Get the element at a given index from a sequence
     */
    template <typename Sequence, std::size_t I>
    using at = typename details::at<I, Sequence>::type;
}

#endif /* !META_SEQUENCE_AT_HPP */
