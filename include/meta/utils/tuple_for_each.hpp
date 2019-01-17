/*
** Created by doom on 16/01/19.
*/

#ifndef META_UTILS_TUPLE_FOR_EACH_HPP
#define META_UTILS_TUPLE_FOR_EACH_HPP

#include <utility>
#include <tuple>

namespace meta
{
    namespace details
    {
        template <typename Tuple, typename Func, std::size_t ...Is>
        void tuple_for_each_helper(Tuple &&t, Func &&func, std::index_sequence<Is...>)
        {
            (func(std::get<Is>(std::forward<Tuple>(t))), ...);
        }
    }

    template <typename Tuple, typename Func>
    void tuple_for_each(Tuple &&t, Func &&func)
    {
        details::tuple_for_each_helper(std::forward<Tuple>(t), std::forward<Func>(func),
                                       std::make_index_sequence<std::tuple_size_v<std::decay_t<Tuple>>>{});
    }
}

#endif /* !META_UTILS_TUPLE_FOR_EACH_HPP */
