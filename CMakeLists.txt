cmake_minimum_required(VERSION 3.21)
project(GDS9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# 添加QT目录
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")
set(CMAKE_PREFIX_PATH "X:/Qt/6.2.1/mingw81_64/lib/cmake")
#set(CMAKE_PREFIX_PATH "D:/Qt/6.2.3/mingw_64/lib/cmake")

# 添加Eigen目录
set(Eigen3_DIR "3rdparty/Eigen3/share/eigen3/cmake")
find_package (Eigen3 3.4 REQUIRED NO_MODULE)
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include(gtest)
include(spdlog)

file(GLOB SRC_LIST src/*.cpp src/reconstruction/*.cpp)

add_executable(GDS9 ${SRC_LIST})
target_link_libraries(GDS9
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Eigen3::Eigen
        gtest
        spdlog::spdlog
        )

if (WIN32)
    set(DEBUG_SUFFIX)
#    if (CMAKE_BUILD_TYPE MATCHES "Debug")
#        set(DEBUG_SUFFIX "d")
#    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()


#add_subdirectory(src/efficiency_calculation)

set(DataAcquisition ON)
option(DataAcquisition "option for DataAcquisition" OFF)
if (DataAcquisition)
    add_subdirectory(src/data_acquisition)
    message("DataAcquisition module on")
endif()

set(TESTS ON)
option(TESTS "option for test" OFF)
if (TESTS)
    message("test module on")
    add_subdirectory(src/tests)
endif()


