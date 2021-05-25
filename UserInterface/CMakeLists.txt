cmake_minimum_required(VERSION 3.1)
project(UI)

set(CMAKE_CXX_STANDARD 17)

include_directories("Client")

find_package(cpprestsdk REQUIRED)

add_executable(ui main.cpp)

add_subdirectory(Client)    

target_link_libraries(ui client)
