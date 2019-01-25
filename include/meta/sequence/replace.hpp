/*
** Created by doom on 20/01/19.
*/

#ifndef META_SEQUENCE_REPLACE_HPP
#define META_SEQUENCE_REPLACE_HPP

#include <meta/sequence/map.hpp>
#include <meta/utils/meta_functions.hpp>

namespace meta
{
    namespace details
    {
        template <template <typename> typename MetaF, typename T>
        struct replace_if_true
        {
            template <typename Arg>
            using func = meta::if_<MetaF<Arg>, T, Arg>;
        };
    }

    template <template <typename> typename MetaF, typename T, typename Sequence>
    using replace = meta::map<
        details::replace_if_true<MetaF, T>::template func,
        Sequence
    >;
}

#endif /* !META_SEQUENCE_REPLACE_HPP */
