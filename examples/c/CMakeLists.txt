cmake_minimum_required(VERSION 3.13)

project(udp_example C)

# Set AFL++ as compiler
set(CMAKE_C_COMPILER afl-clang-fast)
set(CMAKE_CXX_COMPILER afl-clang-fast++)

# Enable ASan for better crash detection
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fsanitize=undefined -g -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=undefined -g -O2")


set(CMAKE_C_STANDARD 11)

find_package(MAVLink REQUIRED)

add_executable(udp_example udp_example.c)

target_link_libraries(udp_example PRIVATE MAVLink::mavlink)
