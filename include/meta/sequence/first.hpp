/*
** Created by doom on 01/01/19.
*/

#ifndef META_SEQUENCE_FIRST_HPP
#define META_SEQUENCE_FIRST_HPP

#include <meta/sequence/list.hpp>
#include <meta/sequence/at.hpp>

namespace meta
{
    template <typename Sequence>
    using first = at<Sequence, 0>;
}

#endif /* !META_SEQUENCE_FIRST_HPP */
