/*
** Created by doom on 29/12/18.
*/

#ifndef META_SEQUENCE_ALL_HPP
#define META_SEQUENCE_ALL_HPP

#include <meta/sequence/list.hpp>

namespace meta
{
    namespace details
    {
        template <template <typename ...> typename MetaF, typename Sequence>
        struct all;

        template <template <typename ...> typename MetaF, typename ...Types>
        struct all<MetaF, list<Types...>> : std::bool_constant<((MetaF<Types>::value) && ...)>
        {
        };
    }

    template <template <typename ...> typename MetaF, typename Sequence>
    using all = details::all<MetaF, Sequence>;
}

#endif /* !META_SEQUENCE_ALL_HPP */
