cmake_minimum_required(VERSION 3.5)

PROJECT(second)

include_directories(/usr/local/boost/include)
link_directories( /usr/local/boost/lib)

set(IMPORTLIB  
   -lrt
   -pthread
)



add_executable(second main.cpp)
target_link_libraries(second ${IMPORTLIB})