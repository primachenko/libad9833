cmake_minimum_required(VERSION 2.8.11)
project(ad9833)

add_subdirectory(test)

add_definitions(-Wall)

include_directories(include)

add_definitions(-DAD9833_DEBUG)
add_definitions(-DDEV_DEBUG)
# add_definitions(-DUSE_SOFT_SPI)

set(SRC
    src/AD9833.c
    src/DEV_Config.c)

add_library(${PROJECT_NAME} STATIC ${SRC})
target_link_libraries(${PROJECT_NAME} bcm2835)