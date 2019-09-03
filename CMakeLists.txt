cmake_minimum_required (VERSION 2.6)
project (Hello)
add_executable(Hello main.cpp)

target_include_directories(Hello PUBLIC /home/attila/dev/projects/spdlog/include)