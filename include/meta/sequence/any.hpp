/*
** Created by doom on 29/12/18.
*/

#ifndef META_SEQUENCE_ANY_HPP
#define META_SEQUENCE_ANY_HPP

#include <meta/sequence/list.hpp>

namespace meta
{
    namespace details
    {
        template <template <typename ...> typename MetaF, typename Sequence>
        struct any;

        template <template <typename ...> typename MetaF, typename ...Types>
        struct any<MetaF, list<Types...>> : std::bool_constant<((MetaF<Types>::value) || ...)>
        {
        };
    }

    template <template <typename ...> typename MetaF, typename Sequence>
    using any = details::any<MetaF, Sequence>;
}

#endif /* !META_SEQUENCE_ANY_HPP */
