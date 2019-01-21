cmake_minimum_required(VERSION 3.9)

project(meta)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")

set(META_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/details/drop_helper.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/details/flatten_helper.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/details/foldl_helper.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/details/index_helper.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/details/rotate_helper.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/details/pow2.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/all.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/any.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/append.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/at.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/concat.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/cons.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/drop.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/drop_at.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/filter.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/flatten.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/foldl.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/from_list.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/head.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/index.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/insert_at.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/join.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/last.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/list.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/map.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/none.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/repeat.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/rotate.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/sequence.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/size.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/split_at.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/tail.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/take.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/unordered_map.hpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/detection/detection.hpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/utils/enum_bitwise_ops.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/utils/integral_constants.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/utils/meta_functions.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/utils/overload_set.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/utils/pair.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/utils/priority_tag.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/utils/rebind.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/utils/recursive_adaptor.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/utils/tuple_for_each.hpp
        )

add_library(meta INTERFACE)

target_sources(meta INTERFACE ${META_SOURCES})

target_include_directories(meta INTERFACE include)

option(META_BUILD_TESTS "Build tests of the meta library" OFF)

if (META_BUILD_TESTS)
    find_package(GTest REQUIRED)

    add_executable(meta-tests
            tests/tests-type_list.cpp
            tests/tests-detection.cpp
            tests/tests-enum_bitwise_ops.cpp
            tests/tests-integral_constants.cpp
            tests/tests-meta_functions.cpp
            tests/tests-type_map.cpp
            tests/tests-overload_set.cpp
            tests/tests-priority_tag.cpp
            tests/tests-rebind.cpp
            tests/tests-recursive_adaptor.cpp
            tests/tests-tuple_for_each.cpp
            )

    target_link_libraries(meta-tests meta GTest::GTest GTest::Main)
endif ()
