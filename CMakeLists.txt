cmake_minimum_required(VERSION 3.9)

project(meta)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")

set(META_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/details/flatten_helper.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/details/pow2.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/concat.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/size.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/flatten.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/join.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/map.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/filter.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/at.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/list.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/meta/meta.hpp
        )

add_library(meta INTERFACE)

target_sources(meta INTERFACE ${META_SOURCES})

target_include_directories(meta INTERFACE include)

add_executable(meta-tests
        tests/tests-type_list.cpp
        tests/tests-main.cpp)

target_link_libraries(meta-tests meta)
