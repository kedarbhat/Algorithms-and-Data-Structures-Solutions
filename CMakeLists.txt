cmake_minimum_required(VERSION 3.12)
project(AlgosAndDS CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if (${CXX})
    set(CMAKE_CXX_COMPILER ${CXX})
endif()
if (${CC})
    set(CMAKE_CC_COMPILER ${CC})
endif()

set(CMAKE_CXX_STANDARD 14)


if ("x{CMAKE_CXX_COMPILER_ID}" STREQUAL "xCLANG")
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-v -Weverything -Wall -Wextra -Wpedantic -Wno-c++98-compat -Wno-c++98-compat-pedantic")
elseif("x{CMAKE_CXX_COMPILER_ID}" STREQUAL "xGNU")
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-v -Wall -Wextra -Wpedantic -Wall -O0")
endif()

add_library(AlgosAndDS INTERFACE)
target_include_directories(AlgosAndDS INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)
target_include_directories(AlgosAndDS SYSTEM INTERFACE $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/src>)
include_directories(src)

find_package(GTest)
add_executable(tests test/main.cpp)
target_link_libraries(tests GTest::GTest)
gtest_discover_tests(tests)

