/*
** Created by doom on 16/01/19.
*/

#ifndef META_UTILS_ENUM_OPS_HPP
#define META_UTILS_ENUM_OPS_HPP

#include <type_traits>

namespace meta::enum_ops
{
    template <typename T>
    struct enable_for : std::false_type
    {
    };

    template <typename T>
    inline constexpr const bool enable_for_v = enable_for<T>::value;
}

/**
 * /!\ Has to be called in the global namespace.
 *
 * This clearly is meh :/
 */
#define ENABLE_BITWISE_OPS_FOR(T)                                                                       \
    namespace meta::enum_ops                                                                            \
    {                                                                                                   \
        template <>                                                                                     \
        struct enable_for<T> : std::true_type                                                           \
        {                                                                                               \
        };                                                                                              \
    }

#define MAKE_ENUM_BINARY_OPERATOR(op)                                                                   \
    template <typename Enum,                                                                            \
        typename = std::enable_if_t<std::is_enum_v<Enum> && meta::enum_ops::enable_for_v<Enum>>         \
    >                                                                                                   \
    constexpr Enum operator op(Enum a, Enum b)                                                          \
    {                                                                                                   \
        using underlying_type = std::underlying_type_t<Enum>;                                           \
                                                                                                        \
        return static_cast<Enum>(static_cast<underlying_type>(a) op static_cast<underlying_type>(b));   \
    }

MAKE_ENUM_BINARY_OPERATOR(|);

MAKE_ENUM_BINARY_OPERATOR(&);

MAKE_ENUM_BINARY_OPERATOR(^);

#undef MAKE_ENUM_BINARY_OPERATOR

#define MAKE_ENUM_ASSIGN_OPERATOR(op)                                                                   \
    template <typename Enum,                                                                            \
        typename = std::enable_if_t<std::is_enum_v<Enum> && meta::enum_ops::enable_for_v<Enum>>         \
    >                                                                                                   \
    constexpr Enum &operator op##=(Enum &a, Enum b)                                                     \
    {                                                                                                   \
        a = a op b;                                                                                     \
        return a;                                                                                       \
    }

MAKE_ENUM_ASSIGN_OPERATOR(|);

MAKE_ENUM_ASSIGN_OPERATOR(&);

MAKE_ENUM_ASSIGN_OPERATOR(^);

#undef MAKE_ENUM_ASSIGN_OPERATOR

template <typename Enum, typename = std::enable_if_t<std::is_enum_v<Enum> && meta::enum_ops::enable_for_v<Enum>>>
constexpr Enum operator~(Enum a)
{
    using underlying_type = std::underlying_type_t<Enum>;

    return static_cast<Enum>(~static_cast<underlying_type >(a));
}

#endif /* !META_UTILS_ENUM_OPS_HPP */
