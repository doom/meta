/*
** Created by doom on 17/01/19.
*/

#include <gtest/gtest.h>
#include <meta/utils/enum_bitwise_ops.hpp>

enum class test : uint8_t
{
    value_0 = 0,
    value_1 = 1,
    value_2 = 2,
    value_3 = 3,
    value_255 = 255,
};

ENABLE_BITWISE_OPS_FOR(test);

static_assert((test::value_1 | test::value_2) == test::value_3);
static_assert((test::value_3 & test::value_2) == test::value_2);

TEST(utils, enum_bitwise_ops)
{
    test t = test::value_1;

    t |= test::value_2;
    ASSERT_EQ(t, test::value_3);

    t = test::value_255;
    ASSERT_EQ(~t, test::value_0);
}
