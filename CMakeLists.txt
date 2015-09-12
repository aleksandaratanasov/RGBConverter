project(RGBConverter)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
include_directories(. INCLUDES)
add_library(rgbconverter SHARED RGBConverter.cpp)


# Optional - create a small demo and tests
# Google C++ Test
# In many Linux distributions you can find libgtest-dev as upstream package
# However in order to use the library you have to build it. I recommend building
# gtest with the BUILD_SHARED_LIBS flag set to ON
# Instructions:
# - Install libgtest-dev
# - Go to /usr/src/gtest
# NOTE: following require superuser priveleges (`sudo`)
# - Created a build directory and enter it
# - Execute `cmake -DBUILD_SHARED_LIBS ..` from inside the build directory
# - Execute `make`
# - Use the `mv` command to move the libraries (two *.so files) to /usr/lib/
# find_package(GTest) should now be able to find them
option(BUILD_TESTS "Build Google Test and a small demo" OFF)
if(BUILD_TESTS)
    message("Google test will be build")
    enable_testing()
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} main.cpp)
    target_link_libraries(${PROJECT_NAME} rgbconverter gtest)
endif()
