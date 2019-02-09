/*
** Created by doom on 19/01/19.
*/

#ifndef META_UTILS_META_FUNCTIONS_HPP
#define META_UTILS_META_FUNCTIONS_HPP

namespace meta
{
    template <typename T>
    using identity = T;

    namespace details
    {
        template <bool>
        struct if_c_helper
        {
            template <typename T, typename F>
            using type = T;
        };

        template <>
        struct if_c_helper<false>
        {
            template <typename T, typename F>
            using type = F;
        };
    }

    template <bool b, typename T, typename F>
    using if_c = typename details::if_c_helper<b>::template type<T, F>;

    template <typename Bool, typename T, typename F>
    using if_ = if_c<static_cast<bool>(Bool::value), T, F>;

    namespace details
    {
        template <template <typename> typename MetaF1, template <typename> typename MetaF2>
        struct compose
        {
            template <typename T>
            using func = MetaF1<MetaF2<T>>;
        };
    }

    /** Compose two meta functions
     * The rightmost is called first
     */
    template <template <typename> typename MetaF1, template <typename> typename MetaF2>
    using compose = details::compose<MetaF1, MetaF2>;
}

#endif /* !META_UTILS_META_FUNCTIONS_HPP */
