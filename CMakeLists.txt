cmake_minimum_required(VERSION 3.12)
project(curve-fitting)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE
        src/Matrix.cpp
        src/Dataset.cpp
        src/PolyEquation.cpp
        src/LogEquation.cpp)

add_executable("${PROJECT_NAME}-bin" ${SOURCE} main.cpp)
set_target_properties("${PROJECT_NAME}-bin" PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
target_include_directories("${PROJECT_NAME}-bin" PUBLIC include)
