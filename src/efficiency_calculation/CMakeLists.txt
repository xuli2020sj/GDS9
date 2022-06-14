cmake_minimum_required(VERSION 3.21)
project(efficiencyCalculation)

set(CMAKE_CXX_STANDARD 17)

include_directories(./3rdparty)

file(GLOB src_list ./*.cpp ./*.h )
add_executable(DECal ${src_list})
