/*
** Created by doom on 13/01/19.
*/

#ifndef META_SEQUENCE_UNORDERED_MAP_HPP
#define META_SEQUENCE_UNORDERED_MAP_HPP

#include <meta/utils/pair.hpp>

namespace doom::meta
{
    namespace details
    {
        template <typename T>
        struct is_pair : std::false_type
        {
        };

        template <typename A, typename B>
        struct is_pair<meta::pair<A, B>> : std::true_type
        {
        };
    }

    template <typename ...Pairs>
    struct unordered_map
    {
        static_assert((details::is_pair<Pairs>::value && ...), "meta::unordered_map: the elements should be pairs");
    };
}

#endif /* !META_SEQUENCE_UNORDERED_MAP_HPP */
