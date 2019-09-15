/*
** Created by doom on 01/01/19.
*/

#ifndef META_SEQUENCE_LAST_HPP
#define META_SEQUENCE_LAST_HPP

#include <meta/utils/integral_constants.hpp>
#include <meta/sequence/list.hpp>
#include <meta/sequence/at.hpp>
#include <meta/sequence/size.hpp>

namespace doom::meta
{
    template <typename Sequence>
    using last = at<Sequence, size_constant<size<Sequence>::value - 1>>;
}

#endif /* !META_SEQUENCE_LAST_HPP */
