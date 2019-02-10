/*
** Created by doom on 30/10/18.
*/

#include <type_traits>
#include <meta/utils/integral_constants.hpp>
#include <meta/sequence/sequence.hpp>

using meta::size_constant;

static_assert(meta::size<meta::list<int, char, bool>>::value == 3);
static_assert(meta::size<meta::list<int, char>>::value == 2);
static_assert(meta::size<meta::list<>>::value == 0);

using A = meta::list<int, char>;
using B = meta::list<double, float>;
using C = meta::join<A, B>;
static_assert(std::is_same_v<meta::list<int, char, double, float>, C>);

using int_char_bool = meta::list<int, char, bool>;

using regular_types = meta::list<
    int, char, bool, double, float, int, char, bool, double, float,
    int, char, bool, double, float, int, char, bool, double, float,
    int, char, bool, double, float, int, char, bool, double, float,
    int, char, bool, double, float, int, char, bool, double, float,
    int, char, bool, double, float, int, char, bool, double, float,
    int, char, bool, double, float, int, char, bool, double, float,
    int, char, bool, double, float, int, char, bool, double, float,
    int, char, bool, double, float, int, char, bool, double, float,
    int, char, bool, double, float, int, char, bool, double, float,
    int, char, bool, double, float, int, char, bool, double, float,
    int, char, bool, double, float, int, char, bool, double, float,
    int, char, bool, double, float, int, char, bool, double, float
>;

using pointer_types = meta::list<
    int *, char *, bool *, double *, float *, int *, char *, bool *, double *, float *,
    int *, char *, bool *, double *, float *, int *, char *, bool *, double *, float *,
    int *, char *, bool *, double *, float *, int *, char *, bool *, double *, float *,
    int *, char *, bool *, double *, float *, int *, char *, bool *, double *, float *,
    int *, char *, bool *, double *, float *, int *, char *, bool *, double *, float *,
    int *, char *, bool *, double *, float *, int *, char *, bool *, double *, float *,
    int *, char *, bool *, double *, float *, int *, char *, bool *, double *, float *,
    int *, char *, bool *, double *, float *, int *, char *, bool *, double *, float *,
    int *, char *, bool *, double *, float *, int *, char *, bool *, double *, float *,
    int *, char *, bool *, double *, float *, int *, char *, bool *, double *, float *,
    int *, char *, bool *, double *, float *, int *, char *, bool *, double *, float *,
    int *, char *, bool *, double *, float *, int *, char *, bool *, double *, float *
>;

using D = meta::map<std::add_pointer_t, regular_types>;
static_assert(std::is_same_v<D, pointer_types>);

using E = meta::list<int, int *, char, char *, float *, float &>;

static_assert(std::is_same_v<meta::list<>, meta::filter<std::is_pointer, regular_types>>);
static_assert(std::is_same_v<meta::list<>, meta::filter<std::is_void, regular_types>>);
static_assert(std::is_same_v<meta::list<>, meta::filter<std::is_reference, regular_types>>);
static_assert(std::is_same_v<pointer_types, meta::filter<std::is_pointer, pointer_types>>);
static_assert(std::is_same_v<meta::list<int *, char *, float *>, meta::filter<std::is_pointer, E>>);

static_assert(std::is_same_v<meta::at<E, size_constant<2>>, char>);
static_assert(std::is_same_v<meta::at<E, size_constant<0>>, int>);
static_assert(std::is_same_v<meta::at<pointer_types, size_constant<30>>, int *>);
static_assert(std::is_same_v<meta::at<regular_types, size_constant<30>>, int>);

static_assert(meta::all<std::is_pointer, pointer_types>::value);
static_assert(not meta::all<std::is_pointer, regular_types>::value);
static_assert(not meta::all<std::is_pointer, E>::value);

static_assert(meta::any<std::is_pointer, pointer_types>::value);
static_assert(not meta::any<std::is_pointer, regular_types>::value);
static_assert(meta::any<std::is_pointer, E>::value);

static_assert(not meta::none<std::is_pointer, pointer_types>::value);
static_assert(meta::none<std::is_pointer, regular_types>::value);
static_assert(not meta::none<std::is_pointer, E>::value);

template <int i>
using int_ = std::integral_constant<int, i>;

template <typename A, typename B>
using meta_add = int_<A::value + B::value>;

using nums = meta::list<
    int_<0>, int_<1>, int_<2>, int_<3>, int_<4>, int_<5>, int_<6>, int_<7>, int_<8>, int_<9>, int_<10>,
    int_<11>, int_<12>, int_<13>, int_<14>, int_<15>, int_<16>, int_<17>, int_<18>, int_<19>, int_<20>,
    int_<21>, int_<22>, int_<23>, int_<24>, int_<25>, int_<26>, int_<27>, int_<28>, int_<29>, int_<30>,
    int_<31>, int_<32>, int_<33>, int_<34>, int_<35>, int_<36>, int_<37>, int_<38>, int_<39>, int_<40>,
    int_<41>, int_<42>, int_<43>, int_<44>, int_<45>, int_<46>, int_<47>, int_<48>, int_<49>, int_<50>,
    int_<51>, int_<52>, int_<53>, int_<54>, int_<55>, int_<56>, int_<57>, int_<58>, int_<59>, int_<60>,
    int_<61>, int_<62>, int_<63>, int_<64>, int_<65>, int_<66>, int_<67>, int_<68>, int_<69>, int_<70>,
    int_<71>, int_<72>, int_<73>, int_<74>, int_<75>, int_<76>, int_<77>, int_<78>, int_<79>, int_<80>,
    int_<81>, int_<82>, int_<83>, int_<84>, int_<85>, int_<86>, int_<87>, int_<88>, int_<89>, int_<90>,
    int_<91>, int_<92>, int_<93>, int_<94>, int_<95>, int_<96>, int_<97>, int_<98>, int_<99>, int_<100>,
    int_<101>, int_<102>, int_<103>, int_<104>, int_<105>, int_<106>, int_<107>, int_<108>, int_<109>, int_<110>,
    int_<111>, int_<112>, int_<113>, int_<114>, int_<115>, int_<116>, int_<117>, int_<118>, int_<119>>;
static_assert(meta::foldl<meta_add, int_<0>, nums>::value == 7140);

static_assert(std::is_same_v<meta::head<nums>, int_<0>>);
static_assert(std::is_same_v<meta::last<nums>, int_<119>>);
static_assert(std::is_same_v<meta::tail<int_char_bool>, meta::list<char, bool>>);

static_assert(std::is_same_v<meta::cons<int, meta::list<>>, meta::list<int>>);
static_assert(std::is_same_v<meta::cons<int, meta::list<char, bool>>, int_char_bool>);

static_assert(std::is_same_v<meta::rotate<int_char_bool, size_constant<1>>, meta::list<char, bool, int>>);
static_assert(std::is_same_v<meta::rotate<int_char_bool, size_constant<4>>, meta::list<char, bool, int>>);
static_assert(std::is_same_v<meta::rotate<pointer_types, size_constant<10>>, pointer_types>);

static_assert(std::is_same_v<meta::drop<int_char_bool, size_constant<1>>, meta::list<char, bool>>);
static_assert(std::is_same_v<meta::drop<int_char_bool, size_constant<40>>, meta::list<>>);
static_assert(meta::foldl<meta_add, int_<0>, meta::drop<nums, size_constant<11>>>::value == 7085);

static_assert(std::is_same_v<meta::take<int_char_bool, size_constant<0>>, meta::list<>>);
static_assert(std::is_same_v<meta::take<int_char_bool, size_constant<2>>, meta::list<int, char>>);
static_assert(std::is_same_v<meta::take<int_char_bool, size_constant<40>>, int_char_bool>);
static_assert(meta::foldl<meta_add, int_<0>, meta::take<nums, size_constant<11>>>::value == 55);

using F = meta::list<meta::list<int, char>, meta::list<bool>>;
using G = meta::list<meta::list<int, char, bool>, meta::list<>>;
static_assert(std::is_same_v<meta::split_at<int_char_bool, size_constant<2>>, F>);
static_assert(std::is_same_v<meta::split_at<int_char_bool, size_constant<3>>, G>);

static_assert(std::is_same_v<meta::append<int_char_bool, int>, meta::list<int, char, bool, int>>);

static_assert(std::is_same_v<meta::insert_at<int_char_bool, size_constant<2>, int>, meta::list<int, char, int, bool>>);
static_assert(std::is_same_v<meta::insert_at<int_char_bool, size_constant<0>, int>, meta::list<int, int, char, bool>>);

template <typename T>
using is_bool = std::is_same<T, bool>;

template <typename T>
using is_double = std::is_same<T, double>;

template <typename T>
using is_int = std::is_same<T, int>;

template <typename T>
using is_118 = std::is_same<int_<118>, T>;

template <typename T>
using is_62 = std::is_same<int_<62>, T>;

static_assert(meta::index<is_bool, int_char_bool>::value == 2);
static_assert(meta::index<is_int, regular_types>::value == 0);
static_assert(meta::index<is_double, regular_types>::value == 3);
static_assert(meta::index<is_62, nums>::value == 62);
static_assert(meta::index<is_118, nums>::value == 118);
static_assert(meta::index<is_int, meta::list<int>>::value == 0);

static_assert(std::is_same_v<meta::drop_at<int_char_bool, int_<0>>, meta::list<char, bool>>);
static_assert(std::is_same_v<meta::drop_at<int_char_bool, int_<1>>, meta::list<int, bool>>);

using H = meta::repeat<int, int_<5>>;
static_assert(std::is_same_v<H, meta::list<int, int, int, int, int>>);
static_assert(std::is_same_v<meta::repeat<int, int_<0>>, meta::list<>>);

using I = meta::replace<is_int, bool, H>;
static_assert(std::is_same_v<I, meta::list<bool, bool, bool, bool, bool>>);

template <typename A, typename B>
using int_less = std::bool_constant<A::value<B::value>;

using J = meta::list<int_<3>, int_<2>, int_<1>, int_<5>, int_<1>, int_<3>>;
static_assert(std::is_same_v<meta::minimum<int_less, nums>, int_<0>>);
static_assert(std::is_same_v<meta::minimum<int_less, J>, int_<1>>);

using K = meta::zip<meta::list<int_<0>, int_<2>, int_<4>>, meta::list<int_<1>, int_<3>, int_<5>>>;
static_assert(std::is_same_v<
    K,
    meta::list<meta::pair<int_<0>, int_<1>>, meta::pair<int_<2>, int_<3>>, meta::pair<int_<4>, int_<5>>>
>);

using L = meta::unzip<K>;
static_assert(std::is_same_v<
    L,
    meta::pair<meta::list<int_<0>, int_<2>, int_<4>>, meta::list<int_<1>, int_<3>, int_<5>>>
>);
