cmake_minimum_required (VERSION 2.6)
project (Hello CXX)
find_package (Threads REQUIRED)
add_executable(Hello main.cpp)
set(CMAKE_BUILD_TYPE Debug)

target_link_libraries(Hello ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(Hello PUBLIC /home/attila/dev/projects/spdlog/include)