/*
** Created by doom on 30/10/18.
*/

#include <type_traits>
#include <meta/meta.hpp>

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
static_assert(std::is_same_v<pointer_types , meta::filter<std::is_pointer, pointer_types>>);
static_assert(std::is_same_v<meta::list<int *, char *, float *>, meta::filter<std::is_pointer, E>>);

static_assert(std::is_same_v<meta::at<E, 2>, char>);
static_assert(std::is_same_v<meta::at<E, 0>, int>);
static_assert(std::is_same_v<meta::at<pointer_types, 30>, int *>);
static_assert(std::is_same_v<meta::at<regular_types, 30>, int>);
