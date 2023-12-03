add_library(Shader Shader.cpp)
target_include_directories(Shader PRIVATE ${CMAKE_SOURCE_DIR}/Platform/OpenGL)
target_link_libraries(Shader PRIVATE GLShader)

add_library(VertexBuffer VertexBuffer.cpp)
target_include_directories(VertexBuffer PRIVATE ${CMAKE_SOURCE_DIR}/Platform/OpenGL)
target_link_libraries(VertexBuffer PRIVATE GLVertexBuffer)

add_library(VertexArray VertexArray.cpp)
target_include_directories(VertexArray PRIVATE ${CMAKE_SOURCE_DIR}/Platform/OpenGL)
target_link_libraries(VertexArray PRIVATE GLVertexArray)

add_library(ElementArray ElementArray.cpp)
target_include_directories(ElementArray PRIVATE ${CMAKE_SOURCE_DIR}/Platform/OpenGL)
target_link_libraries(ElementArray PRIVATE GLElementArray)

add_library(Texture Texture.cpp)
target_include_directories(Texture PRIVATE ${CMAKE_SOURCE_DIR}/Platform/OpenGL)
target_link_libraries(Texture PRIVATE GLTexture)

add_library(RendererCommand RendererCommand.cpp)
target_include_directories(RendererCommand PRIVATE ${CMAKE_SOURCE_DIR}/Platform/OpenGL)
target_link_libraries(RendererCommand PRIVATE GLRendererCommand)

add_library(Renderer Renderer.cpp)
target_include_directories(Renderer PRIVATE ${CMAKE_SOURCE_DIR}/Platform/OpenGL)
target_link_libraries(Renderer PRIVATE RendererCommand)

add_library(Camera Camera.cpp)
target_include_directories(Camera PRIVATE ${CMAKE_SOURCE_DIR}/Thirdparty)