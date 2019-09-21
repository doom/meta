/*
** Created by doom on 30/12/18.
*/

#ifndef META_SEQUENCE_FOLDL_HPP
#define META_SEQUENCE_FOLDL_HPP

#include <meta/sequence/list.hpp>
#include <meta/sequence/unordered_map.hpp>
#include <meta/sequence/details/foldl_helper.hpp>

namespace doom::meta
{
    namespace details
    {
        template <template <typename ...> typename MetaF, typename Initial, typename Sequence>
        struct foldl;

        template <template <typename ...> typename MetaF, typename Initial, typename ...Types>
        struct foldl<MetaF, Initial, list<Types...>>
        {
            using type = typename foldl_helper<choose_foldl_step(sizeof...(Types))>::template f<
                MetaF, Initial, Types...
            >;
        };

        template <template <typename ...> typename MetaF, typename Initial, typename ...Types>
        struct foldl<MetaF, Initial, unordered_map<Types...>>
        {
            using type = typename foldl_helper<choose_foldl_step(sizeof...(Types))>::template f<
                MetaF, Initial, Types...
            >;
        };
    }

    template <template <typename ...> typename MetaF, typename Initial, typename Sequence>
    using foldl = typename details::foldl<MetaF, Initial, Sequence>::type;
}

#endif /* !META_SEQUENCE_FOLDL_HPP */
