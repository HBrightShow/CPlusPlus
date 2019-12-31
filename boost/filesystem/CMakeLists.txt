cmake_minimum_required(VERSION 3.5)

PROJECT(filesystem)

add_definitions(-std=c++14)

include_directories(/usr/local/boost/include)
link_directories( /usr/local/boost/lib)

set(IMPORTLIB
    -lboost_system
    -lboost_filesystem
    -lboost_thread
    -lpthread
)



add_executable(filesystem main.cpp)
target_link_libraries(filesystem ${IMPORTLIB})