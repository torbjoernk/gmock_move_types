cmake_minimum_required(VERSION 3.5)
project(gmock_move_types
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD "14")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest)
include_directories(googletest/googletest/include)
include_directories(googletest/googlemock/include)

set(SOURCE_FILES main.cpp)

add_executable(gmock_move_types ${SOURCE_FILES})
target_link_libraries(gmock_move_types
                      PUBLIC gmock_main)
