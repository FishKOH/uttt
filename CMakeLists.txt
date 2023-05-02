cmake_minimum_required(VERSION 3.8)

project(uttt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_library(libuttt STATIC
    src/domain/types.h
    src/domain/types.cpp
)

target_include_directories(libuttt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(uttt
    src/main.cpp
)

target_link_libraries(uttt PRIVATE libuttt)



set(UTTT_UNIT_TESTS OFF)
if (UTTT_UNIT_TESTS)
    add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/tests")
endif ()
