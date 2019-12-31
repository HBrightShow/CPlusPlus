cmake_minimum_required(VERSION 3.5)

PROJECT(BPIRecv)

include_directories(/usr/local/boost/include)
link_directories( /usr/local/boost/lib)

set(IMPORTLIB  
   -lrt
   -pthread
)



add_executable(BPIRecv main.cpp)
target_link_libraries(BPIRecv ${IMPORTLIB})