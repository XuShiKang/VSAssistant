cmake_minimum_required(VERSION 3.10)
project(VSAssistant)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPATH=\"\\\"${PROJECT_SOURCE_DIR}\\\"\"")

include_directories(${PROJECT_SOURCE_DIR}/include)

FILE(GLOB_RECURSE sourceFiles "src/*.cpp")

add_executable(VSAssistant main.cpp ${sourceFiles})