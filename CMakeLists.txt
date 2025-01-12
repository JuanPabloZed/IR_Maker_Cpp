cmake_minimum_required(VERSION 3.5)

project(IR_Maker VERSION 1.0.3 LANGUAGES CXX)

set(VERBOSE 1)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS PrintSupport)
find_package(Qt6 REQUIRED COMPONENTS Multimedia)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

add_compile_options(/Zc:__cplusplus
                    /permissive-
                    /MP5
                    )

qt_add_executable(IR_Maker
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
    about.h about.cpp about.ui
    add.qrc
    sweepgenerator.h sweepgenerator.cpp sweepgenerator.ui
    qcustomplot.cpp
    icon.o
)

target_link_libraries(IR_Maker PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt6::PrintSupport)
target_link_libraries(IR_Maker PRIVATE Qt6::Multimedia)

set_target_properties(IR_Maker PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

set(EXECUTABLE_OUTPUT_PATH "../../bin")

include(GNUInstallDirs)
install(TARGETS IR_Maker
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(IR_Maker)
endif()
