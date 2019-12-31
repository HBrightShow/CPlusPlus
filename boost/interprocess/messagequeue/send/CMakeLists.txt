cmake_minimum_required(VERSION 3.5)

PROJECT(BPISend)

include_directories(/usr/local/boost/include)
link_directories( /usr/local/boost/lib)

set(IMPORTLIB  
   -lrt
   -pthread
)



add_executable(BPISend main.cpp)
target_link_libraries(BPISend ${IMPORTLIB})