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
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/filter.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/flatten.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/foldl.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/head.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/index.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/insert_at.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/join.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/last.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/list.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/map.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/rotate.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/sequence.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/size.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/split_at.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/tail.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/sequence/take.hpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/detection/detection.hpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/utils/integral_constants.hpp
        )

add_library(meta INTERFACE)

target_sources(meta INTERFACE ${META_SOURCES})

target_include_directories(meta INTERFACE include)

add_executable(meta-tests
        tests/tests-type_list.cpp
        tests/tests-detection.cpp
        tests/tests-main.cpp)

target_link_libraries(meta-tests meta)
