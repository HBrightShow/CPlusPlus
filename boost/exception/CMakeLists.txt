cmake_minimum_required(VERSION 3.5)

PROJECT(exception)

add_definitions(-std=c++14)

include_directories(/usr/local/boost/include)
link_directories( /usr/local/boost/lib)

set(IMPORTLIB

    -lboost_system
    -lpthread

)



add_executable(exception main.cpp)
target_link_libraries(exception ${IMPORTLIB})