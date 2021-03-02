cmake_minimum_required(VERSION 3.10)

project(crawler)

include_directories(${PROJECT_SOURCE_DIR} ./curl/include)
file(GLOB CPP Page.cpp PageLoader.cpp, test.cpp)

add_executable(${PROJECT_NAME} ${CPP})