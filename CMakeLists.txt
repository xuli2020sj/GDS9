cmake_minimum_required(VERSION 3.21)
project(GDS9)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#set(CMAKE_PREFIX_PATH "X:/Qt/6.2.1/mingw81_64/lib/cmake")
set(CMAKE_PREFIX_PATH "D:/Qt/6.2.3/mingw_64/lib/cmake")
set(Eigen3_DIR "3rdparty/Eigen3/share/eigen3/cmake")

include_directories(3rdparty/spdlog/include)
find_package (Eigen3 3.4 REQUIRED NO_MODULE)
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        #URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/gtest
)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.8.3
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/spdlog
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest spdlog)

#file(GLOB_RECURSE src_glob src/*.cpp)
file(GLOB SRC_LIST src/*.cpp)
include_directories(src)
add_executable(GDS9 ${SRC_LIST})

target_link_libraries(GDS9
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Eigen3::Eigen
        gtest
        spdlog::spdlog
        )

#include(GoogleTest)
#gtest_discover_tests(GDS9)

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

add_subdirectory(src/tests)
add_subdirectory(src/reconstruction)