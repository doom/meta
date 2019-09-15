/*
** Created by doom on 13/01/19.
*/

#include <type_traits>
#include <meta/sequence/sequence.hpp>

using signed_to_unsigned = doom::meta::unordered_map<
        doom::meta::pair<signed char, unsigned char>,
        doom::meta::pair<short, unsigned short>,
        doom::meta::pair<int, unsigned int>,
        doom::meta::pair<long, unsigned long>
>;

static_assert(std::is_same_v<doom::meta::at<signed_to_unsigned, signed char>, unsigned char>);
static_assert(std::is_same_v<doom::meta::at<signed_to_unsigned, short>, unsigned short>);
static_assert(std::is_same_v<doom::meta::at < signed_to_unsigned, int>, unsigned int > );
static_assert(std::is_same_v<doom::meta::at < signed_to_unsigned, long>, unsigned long > );

using smaller_to_bigger = doom::meta::unordered_map<
        doom::meta::pair<char, short>,
        doom::meta::pair<short, int>,
        doom::meta::pair<int, long>
>;

using smaller_to_bigger2 = doom::meta::append<smaller_to_bigger, doom::meta::pair<long, long long>>;

static_assert(std::is_same_v<
        smaller_to_bigger2,
        doom::meta::unordered_map<
                doom::meta::pair<char, short>,
                doom::meta::pair<short, int>,
                doom::meta::pair<int, long>,
                doom::meta::pair<long, long long>
        >
>);

static_assert(doom::meta::size<signed_to_unsigned>::value == 4);
static_assert(doom::meta::size<smaller_to_bigger>::value == 3);

template<typename T>
using smaller_than_int = std::bool_constant<sizeof(T) < sizeof(int)>;

template<typename KeyValue>
using key_smaller_than_int = smaller_than_int<typename KeyValue::first_type>;

using smols = doom::meta::filter<key_smaller_than_int, smaller_to_bigger2>;
static_assert(std::is_same_v<
        smols,
        doom::meta::unordered_map<
                doom::meta::pair<char, short>,
                doom::meta::pair<short, int>
        >
>);

static_assert(doom::meta::all<key_smaller_than_int, smols>::value);
static_assert(doom::meta::any<key_smaller_than_int, smols>::value);
static_assert(not doom::meta::all<key_smaller_than_int, smaller_to_bigger2>::value);
static_assert(doom::meta::any<key_smaller_than_int, smaller_to_bigger2>::value);

template<int Value>
using int_ = std::integral_constant<int, Value>;

using numbers_identity = doom::meta::unordered_map<
        doom::meta::pair<int_<0>, int_<0>>,
        doom::meta::pair<int_<1>, int_<1>>,
        doom::meta::pair<int_<2>, int_<2>>,
        doom::meta::pair<int_<3>, int_<3>>,
        doom::meta::pair<int_<4>, int_<4>>,
        doom::meta::pair<int_<5>, int_<5>>,
        doom::meta::pair<int_<6>, int_<6>>,
        doom::meta::pair<int_<7>, int_<7>>,
        doom::meta::pair<int_<8>, int_<8>>,
        doom::meta::pair<int_<9>, int_<9>>,
        doom::meta::pair<int_<10>, int_<10>>,
        doom::meta::pair<int_<11>, int_<11>>,
        doom::meta::pair<int_<12>, int_<12>>,
        doom::meta::pair<int_<13>, int_<13>>,
        doom::meta::pair<int_<14>, int_<14>>,
        doom::meta::pair<int_<15>, int_<15>>,
        doom::meta::pair<int_<16>, int_<16>>,
        doom::meta::pair<int_<17>, int_<17>>,
        doom::meta::pair<int_<18>, int_<18>>,
        doom::meta::pair<int_<19>, int_<19>>
>;

template<typename T>
using double_int_ = int_<T::value * 2>;

template<typename KeyValue>
using double_value = doom::meta::pair<typename KeyValue::first_type, double_int_<typename KeyValue::second_type>>;

using numbers_double = doom::meta::map<double_value, numbers_identity>;

template<typename Double, typename Simple>
using is_double_of = std::bool_constant<Double::value == 2 * Simple::value>;

template<typename KeyValue>
using is_value_double_of_key = is_double_of<typename KeyValue::second_type, typename KeyValue::first_type>;

static_assert(doom::meta::all<is_value_double_of_key, numbers_double>::value);
static_assert(std::is_same_v<numbers_double, doom::meta::unordered_map<
        doom::meta::pair<int_<0>, int_<0>>,
        doom::meta::pair<int_<1>, int_<2>>,
        doom::meta::pair<int_<2>, int_<4>>,
        doom::meta::pair<int_<3>, int_<6>>,
        doom::meta::pair<int_<4>, int_<8>>,
        doom::meta::pair<int_<5>, int_<10>>,
        doom::meta::pair<int_<6>, int_<12>>,
        doom::meta::pair<int_<7>, int_<14>>,
        doom::meta::pair<int_<8>, int_<16>>,
        doom::meta::pair<int_<9>, int_<18>>,
        doom::meta::pair<int_<10>, int_<20>>,
        doom::meta::pair<int_<11>, int_<22>>,
        doom::meta::pair<int_<12>, int_<24>>,
        doom::meta::pair<int_<13>, int_<26>>,
        doom::meta::pair<int_<14>, int_<28>>,
        doom::meta::pair<int_<15>, int_<30>>,
        doom::meta::pair<int_<16>, int_<32>>,
        doom::meta::pair<int_<17>, int_<34>>,
        doom::meta::pair<int_<18>, int_<36>>,
        doom::meta::pair<int_<19>, int_<38>>
>>);

template<typename A, typename B>
using add_ints = int_<A::value + B::value>;

template<typename Accumulator, typename KeyValue>
using add_keys = add_ints<Accumulator, typename KeyValue::first_type>;

using sum_of_keys = doom::meta::foldl<add_keys, int_<0>, numbers_double>;

static_assert(sum_of_keys::value == 190);
