cmake_minimum_required(VERSION 3.12)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} SYSTEM)

add_executable(test_everything main.cpp)
target_link_libraries(test_everything ${GTEST_LIBRARIES} pthread)
enable_testing()

