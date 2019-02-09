/*
** Created by doom on 09/02/19.
*/

#ifndef META_SEQUENCE_ZIP_HPP
#define META_SEQUENCE_ZIP_HPP

#include <meta/sequence/list.hpp>
#include <meta/utils/pair.hpp>

namespace meta
{
    namespace details
    {
        template <typename Sequence1, typename Seqeuence2>
        struct zip;

        template <typename ...Types1, typename ...Types2>
        struct zip<list<Types1...>, list<Types2...>>
        {
            using type = list<pair<Types1, Types2>...>;
        };
    }

    template <typename Sequence1, typename Sequence2>
    using zip = typename details::zip<Sequence1, Sequence2>::type;
}

#endif /* !META_SEQUENCE_ZIP_HPP */
