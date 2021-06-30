cmake_minimum_required(VERSION 3.1)
project(Search)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH "bin")
set(LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build/lib")

include_directories("Client")
include_directories("UserInterface")

find_package(cpprestsdk REQUIRED)

set(CMAKE_BUILD_TYPE Debug)

add_executable(search main.cpp)

add_subdirectory(Client)    
add_subdirectory(UserInterface)

target_link_libraries(search ui)
target_link_libraries(search client)
target_link_libraries(search -lssl)
target_link_libraries(search -lcrypto)
