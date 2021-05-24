project(PageLoader)

set(CMAKE_BUILD_TYPE Debug)

add_library(pageLoader STATIC Page.cpp PageLoader.cpp)
target_link_libraries(pageLoader -lcurl)
