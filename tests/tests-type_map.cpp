/*
** Created by doom on 13/01/19.
*/

#include <meta/sequence/sequence.hpp>

using signed_to_unsigned = meta::unordered_map<
    meta::pair<signed char, unsigned char>,
    meta::pair<short, unsigned short>,
    meta::pair<int, unsigned int>,
    meta::pair<long, unsigned long>
>;

static_assert(std::is_same_v<meta::at<signed_to_unsigned, signed char>, unsigned char>);
static_assert(std::is_same_v<meta::at<signed_to_unsigned, short>, unsigned short>);
static_assert(std::is_same_v<meta::at<signed_to_unsigned, int>, unsigned int>);
static_assert(std::is_same_v<meta::at<signed_to_unsigned, long>, unsigned long>);
