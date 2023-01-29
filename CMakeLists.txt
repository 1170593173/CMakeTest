cmake_minimum_required(VERSION 3.10)

project(CMakeTemplate VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

# add_compile_options(-Wall -Wextra -pedantic -Werror)
add_compile_options(-Wall -Wextra -pedantic)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe -std=c99")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -std=c++11")

set(CMAKE_BUILD_TYPE Debug)

add_definitions(-DDEBUG -DREAL_COOL_ENGINEER -DTESTQQQ) ##添加宏定义

# option(REAL_COOL_ENGINEER "test" ON)
# message(${TEST_IT_CMAKE})
# if(REAL_COOL_ENGINEER)
# 	add_definitions(-DDEBUG -DREAL_COOL_ENGINEER)
# endif()


include_directories(src/c)
include_directories(others)
include_directories(cJson) ##包含的头文件

file(GLOB_RECURSE MATH_LIB_SRC src/c/math/*.c)
add_library(math STATIC ${MATH_LIB_SRC})

file(GLOB_RECURSE JSON_LIB_SRC cJson/*.cpp)
add_library(mjson STATIC ${JSON_LIB_SRC})## 添加生成静态库所需的文件

file(GLOB_RECURSE LOG src/c/Log/*.cpp)
add_library(mLog STATIC ${LOG}) ## 添加生成静态库所需的文件

add_executable(demo src/c/main.cpp others/myfile.cpp) ##add_executable 表示的编译二进制文件需要包含的源文件
target_link_libraries(demo math mjson mLog pthread) ##添加pthread 连接参数，支持多线程变成的编译选项