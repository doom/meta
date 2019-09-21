/*
** Created by doom on 29/11/18.
*/

#ifndef META_SEQUENCE_JOIN_HPP
#define META_SEQUENCE_JOIN_HPP

#include <meta/sequence/list.hpp>
#include <meta/sequence/flatten.hpp>

namespace doom::meta
{
    /**
     * Join multiple sequences
     */
    template <typename ...Lists>
    using join = flatten<list<Lists...>>;
}

#endif /* !META_SEQUENCE_JOIN_HPP */
