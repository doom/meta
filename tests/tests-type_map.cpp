/*
** Created by doom on 13/01/19.
*/

#include <type_traits>
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

static_assert(meta::all<key_smaller_than_int, smols>::value);
static_assert(meta::any<key_smaller_than_int, smols>::value);
static_assert(not meta::all<key_smaller_than_int, smaller_to_bigger2>::value);
static_assert(meta::any<key_smaller_than_int, smaller_to_bigger2>::value);

template <int Value>
using int_ = std::integral_constant<int, Value>;

using numbers_identity = meta::unordered_map<
    meta::pair<int_<0>, int_<0>>,
    meta::pair<int_<1>, int_<1>>,
    meta::pair<int_<2>, int_<2>>,
    meta::pair<int_<3>, int_<3>>,
    meta::pair<int_<4>, int_<4>>,
    meta::pair<int_<5>, int_<5>>,
    meta::pair<int_<6>, int_<6>>,
    meta::pair<int_<7>, int_<7>>,
    meta::pair<int_<8>, int_<8>>,
    meta::pair<int_<9>, int_<9>>,
    meta::pair<int_<10>, int_<10>>,
    meta::pair<int_<11>, int_<11>>,
    meta::pair<int_<12>, int_<12>>,
    meta::pair<int_<13>, int_<13>>,
    meta::pair<int_<14>, int_<14>>,
    meta::pair<int_<15>, int_<15>>,
    meta::pair<int_<16>, int_<16>>,
    meta::pair<int_<17>, int_<17>>,
    meta::pair<int_<18>, int_<18>>,
    meta::pair<int_<19>, int_<19>>
>;

template <typename T>
using double_int_ = int_<T::value * 2>;

template <typename KeyValue>
using double_value = meta::pair<typename KeyValue::first_type, double_int_<typename KeyValue::second_type>>;

using numbers_double = meta::map<double_value, numbers_identity>;

template <typename Double, typename Simple>
using is_double_of = std::bool_constant<Double::value == 2 * Simple::value>;

template <typename KeyValue>
using is_value_double_of_key = is_double_of<typename KeyValue::second_type, typename KeyValue::first_type>;

static_assert(meta::all<is_value_double_of_key, numbers_double>::value);
static_assert(std::is_same_v<numbers_double, meta::unordered_map<
    meta::pair<int_<0>, int_<0>>,
    meta::pair<int_<1>, int_<2>>,
    meta::pair<int_<2>, int_<4>>,
    meta::pair<int_<3>, int_<6>>,
    meta::pair<int_<4>, int_<8>>,
    meta::pair<int_<5>, int_<10>>,
    meta::pair<int_<6>, int_<12>>,
    meta::pair<int_<7>, int_<14>>,
    meta::pair<int_<8>, int_<16>>,
    meta::pair<int_<9>, int_<18>>,
    meta::pair<int_<10>, int_<20>>,
    meta::pair<int_<11>, int_<22>>,
    meta::pair<int_<12>, int_<24>>,
    meta::pair<int_<13>, int_<26>>,
    meta::pair<int_<14>, int_<28>>,
    meta::pair<int_<15>, int_<30>>,
    meta::pair<int_<16>, int_<32>>,
    meta::pair<int_<17>, int_<34>>,
    meta::pair<int_<18>, int_<36>>,
    meta::pair<int_<19>, int_<38>>
>>);
