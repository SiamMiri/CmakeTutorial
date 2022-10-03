cmake_minimum_required(VERSION 3.16)

if(UNIX)
    project(SecondTry VERSION 0.1 LANGUAGES CXX)
elseif(WIN32)
    project(SecondTry VERSION 0.1 LANGUAGES CXX)
elseif(APPLE)
    project(SecondTry)
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# set(CMAKE_PREFIX_PATH $ENV{DIR_QT6_GCC64})
set(CMAKE_PREFIX_PATH "/home/roroak/Qt/6.3.1/gcc_64") # /lib/cmake
# set(CMAKE_PREFIX_PATH $ENV{Qt6_DIR})
find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)
# find_package(Qt6Core REQUIRED)

#=================== INCLUSION OF Project Files ====================#
# set(FORMS_DIR "${CMAKE_SOURCE_DIR}/forms")
# set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
# set(SOURCE_DIR "${../../src")

set(FORMS_DIR "../forms")
set(INCLUDE_DIR "../include")
set(SOURCE_DIR "../src")

include_directories(${FORMS_DIR})
include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})

file(GLOB_RECURSE SOURCES
    "${FORMS_DIR}/*.ui"
    "${FORMS_DIR}/*.qrc"
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)

#=================== SETUP EXECTUABLE ====================#
# Enable debug logging on RELWITHDEBINFO configuration
set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS
    $<$<CONFIG:RELWITHDEBINFO>:QT_MESSAGELOGCONTEXT>
)

# Add the forms directory to the AUTOUIC search paths
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

# Add the executable

qt_add_executable(appSecondTry
    main.cpp
)

qt_add_qml_module(appSecondTry
    URI SecondTry
    VERSION 1.0
    QML_FILES main.qml 
)

set_target_properties(appSecondTry PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appSecondTry
    PRIVATE Qt6::Quick)

install(TARGETS appSecondTry
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
