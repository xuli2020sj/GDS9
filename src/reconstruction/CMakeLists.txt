cmake_minimum_required(VERSION 3.21)
project(reconstruction)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")

include(spdlog)

set(Eigen3_DIR "../../3rdparty/Eigen3/share/eigen3/cmake")
include_directories(../../3rdparty/Eigen3/include/eigen3)
find_package (Eigen3 3.4 REQUIRED NO_MODULE)

file(GLOB src_list *.cpp *.h)
add_executable(reconstruction ${src_list})

target_link_libraries(reconstruction
        spdlog::spdlog)


