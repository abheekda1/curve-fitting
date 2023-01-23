cmake_minimum_required(VERSION 3.12)
project(curve-fitting)

set(SOURCE
        src/matrix.cpp)

add_executable("${project}-bin" ${SOURCE} main.cpp)
target_include_directories("${project}-bin" PUBLIC include)
