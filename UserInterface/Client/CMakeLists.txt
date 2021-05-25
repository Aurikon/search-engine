cmake_minimum_required(VERSION 3.1)
project(Client)

include_directories("SearchResults")

add_library(client STATIC Client.cpp)

add_subdirectory(SearchResult)

target_link_libraries(client searchResult)