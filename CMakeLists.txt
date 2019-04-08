cmake_minimum_required(VERSION 3.12)
project(HackerRank)

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

add_library(HackerRank INTERFACE)
target_include_directories(HackerRank INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)
target_include_directories(HackerRank SYSTEM INTERFACE $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/src>)

include_directories(BEFORE src)

add_custom_target(git_update
    COMMAND git submodule init
    COMMAND git submodule update
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)
add_library( googletest
    ${PROJECT_SOURCE_DIR}/external/googletest/src/gtest-all.cc
    ${PROJECT_SOURCE_DIR}/external/googletest/src/gtest_main.cc
)
target_include_directories(googletest 
    PUBLIC ${PROJECT_SOURCE_DIR}/external/googletest/include 
           ${PROJECT_SOURCE_DIR}/external/googletest
)
add_dependencies(googletest git_update)
set_source_files_properties(
    ${PROJECT_SOURCE_DIR}/external/googletest/src/gtest-all.cc  
    ${PROJECT_SOURCE_DIR}/external/googletest/src/gtest_main.cc
    PROPERTIES GENERATED 1
)

add_subdirectory(test)
