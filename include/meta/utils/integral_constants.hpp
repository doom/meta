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

    template <typename A, typename B>
    using plus = std::integral_constant<decltype(A::value + B::value), A::value + B::value>;

    template <typename A, typename B>
    using minus = std::integral_constant<decltype(A::value - B::value), A::value - B::value>;

    template <typename A, typename B>
    using multiplies = std::integral_constant<decltype(A::value * B::value), A::value * B::value>;

    template <typename A, typename B>
    using divides = std::integral_constant<decltype(A::value / B::value), A::value / B::value>;

    template <typename A, typename B>
    using modulus = std::integral_constant<decltype(A::value % B::value), A::value % B::value>;

    template <typename A>
    using negate = std::integral_constant<decltype(-A::value), -A::value>;

    template <typename A, typename B>
    using bit_and = std::integral_constant<decltype(A::value & B::value), A::value & B::value>;

    template <typename A, typename B>
    using bit_or = std::integral_constant<decltype(A::value | B::value), A::value | B::value>;

    template <typename A, typename B>
    using bit_xor = std::integral_constant<decltype(A::value ^ B::value), A::value ^ B::value>;

    template <typename A>
    using bit_not = std::integral_constant<decltype(~A::value), ~A::value>;
}

#endif /* !META_UTILS_INTEGRAL_CONSTANTS_HPP */
