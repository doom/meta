/*
** Created by doom on 12/01/19.
*/

#ifndef META_SEQUENCE_INDEX_HPP
#define META_SEQUENCE_INDEX_HPP

#include <meta/sequence/list.hpp>
#include <meta/sequence/details/index_helper.hpp>

namespace meta
{
    namespace details
    {
        template <typename Sequence, template <typename ...> typename MetaF>
        struct index;

        template <typename ...Types, template <typename> typename MetaF>
        struct index<list<Types...>, MetaF>
        {
            static constexpr std::size_t value = index_helper<choose_index_step(
                sizeof...(Types))>::template f<MetaF, 0, Types...>;
            static_assert(value < sizeof...(Types));
            using type = std::integral_constant<std::size_t, value>;
        };
    }

    template <template <typename> typename MetaF, typename Sequence>
    using index = typename details::index<Sequence, MetaF>::type;
}

#endif /* !META_SEQUENCE_INDEX_HPP */
