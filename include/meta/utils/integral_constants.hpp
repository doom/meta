/*
** Created by doom on 13/01/19.
*/

#ifndef META_UTILS_INTEGRAL_CONSTANTS_HPP
#define META_UTILS_INTEGRAL_CONSTANTS_HPP

#include <cstddef>
#include <type_traits>

namespace meta
{
    template <std::size_t Value>
    using size_constant = std::integral_constant<std::size_t, Value>;
}

#endif /* !META_UTILS_INTEGRAL_CONSTANTS_HPP */
