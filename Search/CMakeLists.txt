cmake_minimum_required(VERSION 3.1)
project(SearchServer)

set(CMAKE_CXX_STANDARD 17)

#include_directories("Seacrh")
include_directories("SearchResult")
include_directories("Server")
include_directories("MySQL")

add_executable(searchServer main.cpp)

add_subdirectory(Server)

target_link_libraries(searchServer server)
target_link_libraries(searchServer -lmysqlcppconn)
target_link_libraries(searchServer -lssl)
target_link_libraries(searchServer -lcrypto)
