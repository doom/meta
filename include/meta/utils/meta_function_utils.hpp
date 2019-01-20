/*
** Created by doom on 19/01/19.
*/

#ifndef META_UTILS_META_FUNCTION_UTILS_HPP
#define META_UTILS_META_FUNCTION_UTILS_HPP

namespace meta
{
    namespace details
    {
        template <template <typename> typename MetaF1, template <typename> typename MetaF2>
        struct compose
        {
            template <typename T>
            using func = MetaF1<MetaF2<T>>;
        };
    }

    template <template <typename> typename MetaF1, template <typename> typename MetaF2>
    using compose = details::compose<MetaF1, MetaF2>;
}

#endif /* !META_UTILS_META_FUNCTION_UTILS_HPP */
