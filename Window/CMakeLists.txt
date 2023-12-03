add_library(Window Window.cpp)
target_include_directories(Window PRIVATE ${CMAKE_SOURCE_DIR}/Platform/GLFW)
target_link_libraries(Window PRIVATE GLFWWindow)