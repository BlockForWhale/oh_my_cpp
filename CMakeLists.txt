cmake_minimum_required(VERSION 3.8)
project(cpp_class)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main2/main.cpp main2/student.cpp)
add_executable(cpp_class ${SOURCE_FILES})