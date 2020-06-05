cmake_minimum_required(VERSION 3.14)
project(VSAssistant)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)

FILE(GLOB_RECURSE sourceFiles "src/*.cpp")

add_executable(VSAssistant main.cpp ${sourceFiles})