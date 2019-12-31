cmake_minimum_required(VERSION 3.5)

PROJECT(mapped)

add_definitions(-std=c++14)

include_directories(/usr/local/boost/include)
link_directories( /usr/local/boost/lib)

set(IMPORTLIB  
   -lrt
   -pthread
)



add_executable(mapped main.cpp)
target_link_libraries(mapped ${IMPORTLIB})