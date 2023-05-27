cmake_minimum_required(VERSION 3.23)
project(hazi_0328)
set(CMAKE_CXX_STANDARD 11)
add_compile_definitions(MEMTRACE)

#set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
#set(SDL2_PATH "SDL2-2.26.4/x86_64-w64-mingw32")

#find_package(SDL2 REQUIRED)

#include_directories(${SDL2_INCLUDE_DIR})


set(SDL2_INCLUDE_DIR C:/Users/gombi/Documents/Proglab2/hazi_0328_gfx/MinGW/include/SDL2)
set(SDL2_LIB_DIR C:/Users/gombi/Documents/Proglab2/hazi_0328_gfx/MinGW/lib)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(hazi_0328 main.cpp grafika_.h texture_.h memtrace.h  Parser.h stringList.h
        grafika_.cpp texture_.cpp memtrace.cpp Parser.cpp stringList.cpp config.cpp config.h)
target_link_libraries(${PROJECT_NAME} mingw32 ${SDL2_LIBRARY} SDL2_gfx)
        # SDL2_gfx SDL2main SDL2)