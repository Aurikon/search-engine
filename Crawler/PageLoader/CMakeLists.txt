cmake_minimum_required(VERSION 3.10)

project(PageLoader)

file(GLOB CPP Page.cpp PageLoader.cpp test.cpp)

add_executable(${PROJECT_NAME} ${CPP})

target_link_libraries(${PROJECT_NAME} -lcurl)