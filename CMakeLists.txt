cmake_minimum_required(VERSION 3.23)
project(4A_plans)

set(CMAKE_CXX_STANDARD 14)

add_executable(4A_plans main.cpp)

target_link_libraries(4A_plans 4A_plans_lib)

include_directories(${CMAKE_PROJECT_NAME}_lib)
add_subdirectory(${CMAKE_PROJECT_NAME}_lib)
add_subdirectory(Google_tests)