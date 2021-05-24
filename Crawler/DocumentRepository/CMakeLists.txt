project(DocumentRepository)

set(CMAKE_BUILD_TYPE Debug)

add_library(documentRepository STATIC Document.cpp DocumentRepository.cpp)