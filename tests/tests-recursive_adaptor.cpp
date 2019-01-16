/*
** Created by doom on 15/01/19.
*/

#include <gtest/gtest.h>
#include <meta/utils/recursive_adaptor.hpp>
#include <meta/utils/overload_set.hpp>

TEST(utils, recursive_adaptor)
{
    constexpr auto fact = meta::recursive_adaptor([](auto &&self, int n) constexpr -> int {
        if (n <= 1)
            return 1;
        return n * self(n - 1);
    });
    static_assert(fact(1) == 1);
    static_assert(fact(3) == 6);

    constexpr auto test = meta::recursive_adaptor(meta::make_overload_set([](auto &&self, int n) constexpr -> int {
        if (n <= 1)
            return 1;
        return n * self(n - 1);
    }, [](auto &&, const char *a) constexpr {
        return a[0];
    }));
    static_assert(test(1) == 1);
    static_assert(test(3) == 6);
    static_assert(test("abc") == 'a');
}
