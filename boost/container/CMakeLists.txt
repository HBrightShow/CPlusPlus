cmake_minimum_required(VERSION 3.5)

PROJECT(container)

add_definitions(-std=c++14)

include_directories(/usr/local/boost/include)
link_directories( /usr/local/boost/lib)

set(IMPORTLIB

)



add_executable(container main.cpp)
target_link_libraries(container ${IMPORTLIB})