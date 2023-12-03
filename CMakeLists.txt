cmake_minimum_required(VERSION 3.12)

project(V3Renderer)

add_executable(Main Main.cpp)

target_include_directories(Main PRIVATE ${CMAKE_SOURCE_DIR}/thirdparty)
target_include_directories(Main PRIVATE ${CMAKE_SOURCE_DIR}/Window)
target_include_directories(Main PRIVATE ${CMAKE_SOURCE_DIR}/Sandbox)
target_include_directories(Main PRIVATE ${CMAKE_SOURCE_DIR}/Renderer)

add_subdirectory(${CMAKE_SOURCE_DIR}/Shaders)
add_subdirectory(${CMAKE_SOURCE_DIR}/thirdparty/glad)
add_subdirectory(${CMAKE_SOURCE_DIR}/Platform/OpenGL)
add_subdirectory(${CMAKE_SOURCE_DIR}/Renderer)
add_subdirectory(${CMAKE_SOURCE_DIR}/Platform/GLFW)
add_subdirectory(${CMAKE_SOURCE_DIR}/Window)
add_subdirectory(${CMAKE_SOURCE_DIR}/Sandbox)


target_link_libraries(Main Window RendererApplication)