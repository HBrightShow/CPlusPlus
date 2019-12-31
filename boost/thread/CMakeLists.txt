cmake_minimum_required(VERSION 3.5)

PROJECT(thread)

add_definitions(-std=c++14)

include_directories(/usr/local/boost/include)
link_directories( /usr/local/boost/lib)

set(IMPORTLIB
    -lboost_system
    -lboost_thread
    -lpthread
)



add_executable(thread main.cpp)
target_link_libraries(thread ${IMPORTLIB})