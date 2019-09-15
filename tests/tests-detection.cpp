/*
** Created by doom on 07/01/19.
*/

#include <meta/detection/detection.hpp>

template <typename T>
using member_type_test_detector = typename T::test;

namespace
{
    struct with_test_member_type
    {
        using test = int;
    };

    struct without_test_member_type
    {
    };
}

static_assert(doom::meta::is_detected_v<member_type_test_detector, with_test_member_type>);
static_assert(!doom::meta::is_detected_v<member_type_test_detector, without_test_member_type>);
static_assert(std::is_same_v<doom::meta::type_unless_detected_t<void, member_type_test_detector, with_test_member_type>, int>);
static_assert(std::is_same_v<doom::meta::type_unless_detected_t<void, member_type_test_detector, without_test_member_type>, void>);
