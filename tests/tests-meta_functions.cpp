/*
** Created by doom on 19/01/19.
*/

#include <gtest/gtest.h>
#include <type_traits>
#include <meta/utils/meta_functions.hpp>
#include <meta/utils/integral_constants.hpp>

static_assert(std::is_same_v<doom::meta::identity<int>, int>);

template <typename T>
using div_by_two = doom::meta::divides<T, doom::meta::size_constant<2>>;

template <typename T>
using div_by_four = typename doom::meta::compose<div_by_two, div_by_two>::template func<T>;

static_assert(div_by_four<doom::meta::size_constant<4>>::value == 1);

static_assert(std::is_same_v<doom::meta::if_c<true, int, char>, int>);
static_assert(std::is_same_v<doom::meta::if_c<false, int, char>, char>);
static_assert(std::is_same_v<doom::meta::if_<doom::meta::size_constant<2>, int, char>, int>);
static_assert(std::is_same_v<doom::meta::if_<doom::meta::size_constant<0>, int, char>, char>);
