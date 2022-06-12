cmake_minimum_required(VERSION 3.21)
project(tests)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")
include(gtest)
include(spdlog)

include_directories(../../3rdparty/snap7/src)
link_directories(../../3rdparty/snap7/lib)
file(GLOB snap7_src_list ../../3rdparty/snap7/src/*.cpp)

include_directories(../data_acquisition)
file(GLOB data_acquisition_src_list ../data_acquisition/*.cpp)

include_directories(../reconstruction)
file(GLOB reconstruction_src_list ../reconstruction/*.cpp)

set(Eigen3_DIR "../../3rdparty/Eigen3/share/eigen3/cmake")
include_directories(../../3rdparty/Eigen3/include/eigen3)
find_package (Eigen3 3.4 REQUIRED NO_MODULE)


list(FILTER data_acquisition_src_list EXCLUDE REGEX "main.cpp$")
add_executable(data_acquisition_test test_data_acquisition.cpp
        ${snap7_src_list}
        ${data_acquisition_src_list})
target_link_libraries(data_acquisition_test
        snap7.dll snap7.lib
        spdlog::spdlog
        gtest
        )


add_executable(reconstruction_test test_reconstruction.cpp
        ${reconstruction_src_list}
        )
target_link_libraries(reconstruction_test
        gtest
        spdlog::spdlog
        )



