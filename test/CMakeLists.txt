cmake_minimum_required(VERSION 2.8.11)

add_definitions(-Wall)

include_directories(../include)

add_executable(test_ad9833 test.c)
target_link_libraries(test_ad9833 ad9833)