/*
** Created by doom on 29/11/18.
*/

#ifndef META_SEQUENCE_AT_HPP
#define META_SEQUENCE_AT_HPP

#include <utility>
#include <meta/utils/pair.hpp>
#include <meta/sequence/list.hpp>
#include <meta/sequence/unordered_map.hpp>

namespace doom::meta
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

        template <typename I, typename Sequence>
        struct at;

        template <typename I, typename ...Types>
        struct at<I, list<Types...>>
        {
            static_assert(I::value < sizeof...(Types), "meta::at: index out of range");

            template <typename T>
            static T get(indexed_element<I::value, T>);

            using index_type = indexed_list<std::make_index_sequence<sizeof...(Types)>, Types...>;
            using type = decltype(at::get(index_type{}));
        };

        template <typename ...Pairs>
        struct indexed_map : Pairs...
        {
        };

        template <typename Key, typename ...Keys, typename ...Values>
        struct at<Key, unordered_map<pair<Keys, Values>...>>
        {
            template <typename T>
            static T get(pair<Key, T>);

            using index_type = indexed_map<pair<Keys, Values>...>;
            using type = decltype(get(index_type{}));
        };
    }

    /**
     * Get the element at a given index from a sequence
     */
    template <typename Sequence, typename I>
    using at = typename details::at<I, Sequence>::type;
}

#endif /* !META_SEQUENCE_AT_HPP */
