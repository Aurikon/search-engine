cmake_minimum_required(VERSION 3.1)
project(Crawler)

set(CMAKE_CXX_STANDARD 17)

include_directories("PageLoader")
include_directories("Parser")
include_directories("WebsiteRepository")
include_directories("LinkInfo")
include_directories("DocumentRepository")
include_directories("MySQL")

set(CMAKE_BUILD_TYPE Debug)

add_executable(crawler main.cpp)

add_subdirectory(PageLoader)
add_subdirectory(Parser)
add_subdirectory(LinkInfo)
add_subdirectory(WebsiteRepository)
add_subdirectory(DocumentRepository)


target_link_libraries(crawler parser)
target_link_libraries(crawler pageLoader)
target_link_libraries(crawler linkInfo)
target_link_libraries(crawler websiteRepository)
target_link_libraries(crawler documentRepository)
target_link_libraries(crawler -lmysqlcppconn)