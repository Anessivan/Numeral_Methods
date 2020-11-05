 cmake_minimum_required(VERSION 2.8)
 
 set(PROJECT_NAME numeralmethods)
 
 project(${PROJECT_NAME})
 
 set(SRC_EXE Main.cpp)
 
 set(LIB Methods.h Methods.cpp)
 
 add_library(Methods STATIC ${LIB})
 
 add_executable(main ${SRC_EXE})
 
 target_link_libraries(main Methods)
