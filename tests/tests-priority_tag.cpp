/*
** Created by doom on 16/01/19.
*/

#include <gtest/gtest.h>
#include <meta/utils/priority_tag.hpp>

template <typename T, typename = std::enable_if_t<std::is_same_v<int, T>>>
static constexpr int dummy([[maybe_unused]] T unused, doom::meta::priority_tag<1>)
{
    return 1;
}

template <typename T>
static constexpr int dummy([[maybe_unused]] T unused, doom::meta::priority_tag<0>)
{
    return 2;
}

static_assert(dummy(-2, doom::meta::priority_tag<1>{}) == 1);
static_assert(dummy(3.2, doom::meta::priority_tag<1>{}) == 2);
static_assert(dummy(-2, doom::meta::priority_tag<0>{}) == 2);
