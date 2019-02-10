/*
** Created by doom on 10/02/19.
*/

#ifndef META_SEQUENCE_UNZIP_HPP
#define META_SEQUENCE_UNZIP_HPP

#include <meta/sequence/list.hpp>
#include <meta/utils/pair.hpp>

namespace meta
{
    namespace details
    {
        template <typename Sequence1>
        struct unzip;

        template <typename ...Types1, typename ...Types2>
        struct unzip<list<pair<Types1, Types2>...>>
        {
            using type = pair<list<Types1...>, list<Types2...>>;
        };
    }

    template <typename Sequence>
    using unzip = typename details::unzip<Sequence>::type;
}

#endif /* !META_SEQUENCE_UNZIP_HPP */
