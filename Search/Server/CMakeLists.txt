project(Server)

include_directories("Search")

add_subdirectory(Search)

add_library(server STATIC Server.cpp)

target_link_libraries(server search)