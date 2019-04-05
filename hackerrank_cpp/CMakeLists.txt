cmake_minimum_required(VERSION 3.12)
project(hackerrank_cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if (${CXX})
    set(CMAKE_CXX_COMPILER ${CXX})
endif()
if (${CC})
    set(CMAKE_CC_COMPILER ${CC})
endif()

set(CMAKE_CXX_STANDARD 14)

if ("x{CMAKE_CXX_COMPILER_ID}" STREQUAL "xCLANG")
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Weverything -Wall -Wextra -Wpedantic -Wno-c++98-compat -Wno-c++98-compat-pedantic")
elseif("x{CMAKE_CXX_COMPILER_ID}" STREQUAL "xGNU")
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wextra -Wpedantic")
endif()

add_library(hackerrank_cpp INTERFACE)
target_include_directories(hackerrank_cpp INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)
target_include_directories(hackerrank_cpp SYSTEM INTERFACE $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/src>)

include_directories(BEFORE src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
