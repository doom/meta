/*
** Created by doom on 08/01/19.
*/

#ifndef META_SEQUENCE_APPEND_HPP
#define META_SEQUENCE_APPEND_HPP

#include <meta/sequence/list.hpp>

namespace meta
{
    namespace details
    {
        template <typename Sequence, typename T>
        struct append;

        template <typename ...Types, typename T>
        struct append<list<Types...>, T>
        {
            using type = list<Types..., T>;
        };
    }

    template <typename Sequence, typename T>
    using append = typename details::append<Sequence, T>::type;
}

#endif /* !META_SEQUENCE_APPEND_HPP */
