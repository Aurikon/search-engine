cmake_minimum_required(VERSION 3.1)
project(SearchResult)

add_library(searchResult STATIC SearchResult.cpp)
find_package(cpprestsdk REQUIRED)

target_link_libraries(searchResult PRIVATE cpprestsdk::cpprest)