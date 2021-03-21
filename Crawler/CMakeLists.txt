cmake_minimum_required(VERSION 3.1)
project(Crawler)

include_directories("PageLoader")
include_directories("Parser")

add_executable(test test.cpp)

add_subdirectory(PageLoader)
add_subdirectory(Parser)

target_link_libraries(test parser)
target_link_libraries(test pageLoader)