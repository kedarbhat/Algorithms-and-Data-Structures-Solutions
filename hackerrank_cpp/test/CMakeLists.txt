cmake_minimum_required(VERSION 3.10)
find_package(GTest)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_everything main.cpp)
target_link_libraries(test_everything ${GTEST_LIBRARIES} pthread)
enable_testing()

