/*
** Created by doom on 01/01/19.
*/

#ifndef META_SEQUENCE_ROTATE_HPP
#define META_SEQUENCE_ROTATE_HPP

#include <cstddef>
#include <meta/sequence/list.hpp>
#include <meta/sequence/details/rotate_helper.hpp>

namespace meta
{
    namespace details
    {
        template <typename Sequence, typename N>
        struct rotate;

        template <typename ...Ts, typename N>
        struct rotate<list<Ts...>, N>
        {
            using type = typename details::rotate_helper<
                details::choose_rotate_step(simplify_rotate_num(N::value, sizeof...(Ts)))
            >::template f<simplify_rotate_num(N::value, sizeof...(Ts)), Ts...>;
        };
    }

    template <typename Sequence, typename N>
    using rotate = typename details::rotate<Sequence, N>::type;
}

#endif /* !META_SEQUENCE_ROTATE_HPP */
