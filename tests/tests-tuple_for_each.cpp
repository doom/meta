/*
** Created by doom on 16/01/19.
*/

#include <gtest/gtest.h>
#include <type_traits>
#include <tuple>
#include <meta/utils/tuple_for_each.hpp>

TEST(utils, tuple_for_each)
{
    int sum = 0;
    std::tuple<int, int, int> t1{1, 2, 3};

    meta::tuple_for_each(t1, [&sum](auto &&v) {
        sum += v;
    });
    ASSERT_EQ(sum, 6);

    meta::tuple_for_each(t1, [](auto &&v) {
        static_assert(std::is_same_v<decltype(v), int &>);
    });

    meta::tuple_for_each(std::move(t1), [](auto &&v) {
        static_assert(std::is_same_v<decltype(v), int &&>);
    });

    const std::tuple<int, int, int> t2{1, 2, 3};

    meta::tuple_for_each(t2, [](auto &&v) {
        static_assert(std::is_same_v<decltype(v), const int &>);
    });
}
