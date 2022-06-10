cmake_minimum_required(VERSION 3.21)
project(efficiencyCalculation)

set(CMAKE_CXX_STANDARD 17)

include_directories(./3rdparty)

file(GLOB src_list ./*.cpp ./*.h )
add_executable(DECal ${src_list})


add_library(${PROJECT_NAME} SHARED ${src_list})
set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_NAME Foo
        PREFIX Lib
        SUFFIX .so
        VERSION ${CMAKE_PROJECT_VERSION}
        SOVERSION ${CMAKE_PROJECT_VERSION_MAJOR})