/*
** Created by doom on 19/01/19.
*/

#include <gtest/gtest.h>
#include <meta/utils/meta_function_utils.hpp>
#include <meta/utils/integral_constants.hpp>

template <typename T>
using div_by_two = meta::divides<T, meta::size_constant<2>>;

template <typename T>
using div_by_four = typename meta::compose<div_by_two, div_by_two>::template func<T>;

static_assert(div_by_four<meta::size_constant<4>>::value == 1);
