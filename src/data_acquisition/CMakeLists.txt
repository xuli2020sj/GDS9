cmake_minimum_required(VERSION 3.21)
project(data_acquisition)

set(CMAKE_CXX_STANDARD 17)

include_directories(../../3rdparty/snap7/src)
link_directories(../../3rdparty/snap7/lib)

file(GLOB src_list *.cpp *.h ../../3rdparty/snap7/src/*.cpp)
add_executable(data_acquisition ${src_list})

include(spdlog)
target_link_libraries(data_acquisition
        snap7.dll snap7.lib
        spdlog::spdlog)


