project(RGBConverter)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
include_directories(. INCLUDES)
add_library(rgbconverter SHARED RGBConverter.cpp)


add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} rgbconverter)
