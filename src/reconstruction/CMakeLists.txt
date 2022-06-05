cmake_minimum_required(VERSION 3.20)

project(reconstruction)

set(Eigen3_DIR "../../3rdparty/Eigen3/share/eigen3/cmake")
find_package (Eigen3 3.4 REQUIRED NO_MODULE)

file(GLOB SRC_LIST *.cpp)


foreach(SRC ${SRC_LIST})
    get_filename_component(file ${SRC} NAME_WLE)
    add_executable(${file} ${SRC})
    target_link_libraries(${file} Eigen3::Eigen spdlog::spdlog)
    message(${file})
endforeach()