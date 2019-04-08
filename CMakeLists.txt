cmake_minimum_required(VERSION 3.12)
project(HackerRank CXX)

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
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wextra -Wpedantic -Wall -O0 --coverage")
endif()

add_library(HackerRank INTERFACE)
target_include_directories(HackerRank INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)
target_include_directories(HackerRank SYSTEM INTERFACE $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/src>)
target_compile_options(HackerRank INTERFACE
        -O0        # no optimization
        -g         # generate debug info
        --coverage # sets all required flags
        )
include_directories(BEFORE src)

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} SYSTEM)
include(GoogleTest)

add_executable(test_everything test/main.cpp)
target_link_libraries(test_everything GTest::GTest)
gtest_discover_tests(test_everything)
enable_testing()
