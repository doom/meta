/*
** Created by doom on 13/01/19.
*/

#include <gtest/gtest.h>
#include <meta/utils/overload_set.hpp>

TEST(utils, overload_set)
{
    constexpr auto set1 = doom::meta::make_overload_set([](const int &i) {
        ASSERT_EQ(i, 1);
    }, [](const double &d) {
        ASSERT_EQ(d, 2.3);
    });
    set1(1);
    set1(2.3);

    constexpr auto set2 = doom::meta::make_overload_set([](int i) {
        return i;
    }, [](auto &&) {
        return 0;
    });

    static_assert(set2(1) == 1);
    static_assert(set2(2.3) == 0);
}
