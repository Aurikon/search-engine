project(SearchResult)
find_package(cpprestsdk REQUIRED)
add_library(searchResult STATIC SearchResult.cpp)
target_link_libraries(searchResult PRIVATE cpprestsdk::cpprest)