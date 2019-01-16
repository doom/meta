/*
** Created by doom on 13/01/19.
*/

#ifndef META_UTILS_OVERLOAD_SET_HPP
#define META_UTILS_OVERLOAD_SET_HPP

#include <utility>

namespace meta
{
    template <typename ...Funcs>
    struct overload_set : private Funcs ...
    {
        using Funcs::operator()...;

        template <typename ...FuncsU, typename = std::enable_if_t<(std::is_constructible_v<Funcs, FuncsU> && ...)>>
        constexpr explicit overload_set(FuncsU &&...funcs) : Funcs(std::forward<FuncsU>(funcs))...
        {
        }
    };

    template <typename ...Funcs>
    constexpr auto make_overload_set(Funcs &&...funcs)
    {
        return overload_set<Funcs...>(std::forward<Funcs>(funcs)...);
    }
}

#endif /* !META_UTILS_OVERLOAD_SET_HPP */
