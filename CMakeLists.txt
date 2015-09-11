project(RGBConverter)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE RelwithDebInfo)
#set(CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
include_directories(. INCLUDES)
add_library(rgbconverter SHARED RGBConverter.cpp)


# Optional - create a small demo that shows some of the library's functionality
#add_executable(${PROJECT_NAME} main.cpp)
#target_link_libraries(${PROJECT_NAME} rgbconverter)
