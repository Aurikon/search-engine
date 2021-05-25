project(Search)

include_directories("SearchResult")

add_library(search STATIC Search.cpp)

add_subdirectory(SearchResult)

target_link_libraries(search searchResult)