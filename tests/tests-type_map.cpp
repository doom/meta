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

using smaller_to_bigger = meta::unordered_map<
    meta::pair<char, short>,
    meta::pair<short, int>,
    meta::pair<int, long>
>;

using smaller_to_bigger2 = meta::append<smaller_to_bigger, meta::pair<long, long long>>;

static_assert(std::is_same_v<
    smaller_to_bigger2,
    meta::unordered_map<
        meta::pair<char, short>,
        meta::pair<short, int>,
        meta::pair<int, long>,
        meta::pair<long, long long>
    >
>);

static_assert(meta::size<signed_to_unsigned>::value == 4);
static_assert(meta::size<smaller_to_bigger>::value == 3);

template <typename T>
using smaller_than_int = std::bool_constant<sizeof(T) < sizeof(int)>;

template <typename KeyValue>
using key_smaller_than_int = smaller_than_int<typename KeyValue::first_type>;

using smols = meta::filter<key_smaller_than_int, smaller_to_bigger2>;
static_assert(std::is_same_v<
    smols,
    meta::unordered_map<
        meta::pair<char, short>,
        meta::pair<short, int>
    >
>);
