cmake_minimum_required(VERSION 3.20.0)

project(main)

add_executable(${PROJECT_NAME} main.cpp)


add_subdirectory(external/glfw)
target_include_directories(${PROJECT_NAME} PUBLIC external/glfw/include)
target_link_directories(${PROJECT_NAME} PRIVATE external/glfw/src)
target_link_libraries(${PROJECT_NAME} glfw)