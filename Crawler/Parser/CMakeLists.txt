project(Parser)

set(CMAKE_BUILD_TYPE Debug)

add_library(parser STATIC Parser.cpp)
target_link_libraries(parser -lgumbo)