cmake_minimum_required(VERSION 3.16)
project(task_manager VERSION 1.0 LANGUAGES CXX)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

add_library(task_manager_lib STATIC src/TaskManager.cpp src/Task.cpp)
target_include_directories(task_manager_lib PUBLIC include/)

add_executable(task_manager src/main.cpp)
target_link_libraries(task_manager PRIVATE task_manager_lib)

add_executable(task_manager_test tests/test_task_manager.cpp)
target_link_libraries(task_manager_test PRIVATE task_manager_lib gtest)