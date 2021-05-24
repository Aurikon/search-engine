project(LinkInfo)

set(CMAKE_BUILD_TYPE Debug)

add_library(linkInfo STATIC LinkInfo.cpp LinkInfoRepository.cpp)