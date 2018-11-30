/*
** Created by doom on 29/11/18.
*/

#ifndef META_JOIN_HPP
#define META_JOIN_HPP

#include <meta/list.hpp>
#include <meta/flatten.hpp>

namespace meta
{
    /**
     * Join multiple sequences
     */
    template <typename ...Lists>
    using join = flatten<list<Lists...>>;
}

#endif /* !META_JOIN_HPP */
