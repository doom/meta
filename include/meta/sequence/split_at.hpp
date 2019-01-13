/*
** Created by doom on 06/01/19.
*/

#ifndef META_SEQUENCE_SPLIT_AT_HPP
#define META_SEQUENCE_SPLIT_AT_HPP

#include <cstddef>
#include <meta/sequence/list.hpp>
#include <meta/sequence/take.hpp>
#include <meta/sequence/drop.hpp>

namespace meta
{
    template <typename Sequence, typename N>
    using split_at = meta::list<meta::take<Sequence, N>, meta::drop<Sequence, N>>;
}

#endif /* !META_SEQUENCE_SPLIT_AT_HPP */
