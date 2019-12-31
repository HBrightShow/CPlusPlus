cmake_minimum_required(VERSION 3.5)

PROJECT(signals)

add_definitions(-std=c++14)

include_directories(/usr/local/boost/include)
link_directories( /usr/local/boost/lib)

set(IMPORTLIB
    -lboost_system
    -lboost_thread
    -lpthread
)



add_executable(signals main.cpp)
target_link_libraries(signals ${IMPORTLIB})