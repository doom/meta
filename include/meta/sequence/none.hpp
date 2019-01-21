/*
** Created by doom on 20/01/19.
*/

#ifndef META_SEQUENCE_NONE_HPP
#define META_SEQUENCE_NONE_HPP

#include <meta/sequence/list.hpp>
#include <meta/sequence/unordered_map.hpp>

namespace meta
{
    namespace details
    {
        template <template <typename> typename MetaF, typename Sequence>
        struct none;

        template <template <typename> typename MetaF, typename ...Types>
        struct none<MetaF, list<Types...>> : std::bool_constant<((not MetaF<Types>::value) && ...)>
        {
        };

        template <template <typename> typename MetaF, typename ...Types>
        struct none<MetaF, unordered_map<Types...>> : std::bool_constant<((not MetaF<Types>::value) && ...)>
        {
        };
    }

    template <template <typename> typename MetaF, typename Sequence>
    using none = details::none<MetaF, Sequence>;
}

#endif /* !META_SEQUENCE_NONE_HPP */
