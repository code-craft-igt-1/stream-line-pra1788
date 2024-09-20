cmake_minimum_required(VERSION 3.14)
project(RandomDataGenerator)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")

include(FetchContent)
FetchContent_Declare(
    googletest
    DOWNLOAD_EXTRACT_TIMESTAMP true
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# List all source files explicitly
set(SOURCES
    sender.cpp
)

# Create a library from the sender source file
add_library(sender_lib STATIC ${SOURCES})

# Add the test executable
add_executable(test-sender test-sender.cpp)

# Link the test executable with GoogleTest and the Sender library
target_link_libraries(test-sender GTest::gtest_main sender_lib)

# Discover tests
include(GoogleTest)
gtest_discover_tests(test-sender)
