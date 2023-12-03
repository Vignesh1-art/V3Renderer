add_library(GLShader GLShader.cpp)
target_include_directories(GLShader PRIVATE ${CMAKE_SOURCE_DIR}/Renderer)
target_include_directories(GLShader PRIVATE ${CMAKE_SOURCE_DIR}/thirdparty)

add_library(GLTexture GLTexture.cpp)
target_include_directories(GLTexture PRIVATE ${CMAKE_SOURCE_DIR}/Renderer)
target_include_directories(GLTexture PRIVATE ${CMAKE_SOURCE_DIR}/thirdparty)

add_library(GLVertexBuffer GLVertexBuffer.cpp)
target_include_directories(GLVertexBuffer PRIVATE ${CMAKE_SOURCE_DIR}/Renderer)
target_include_directories(GLVertexBuffer PRIVATE ${CMAKE_SOURCE_DIR}/thirdparty)
target_link_libraries(GLVertexBuffer PUBLIC glad)

add_library(GLVertexArray GLVertexArray.cpp)
target_include_directories(GLVertexArray PRIVATE ${CMAKE_SOURCE_DIR}/Renderer)
target_include_directories(GLVertexArray PRIVATE ${CMAKE_SOURCE_DIR}/thirdparty)

add_library(GLElementArray GLElementArray.cpp)
target_include_directories(GLElementArray PRIVATE ${CMAKE_SOURCE_DIR}/Renderer)
target_include_directories(GLElementArray PRIVATE ${CMAKE_SOURCE_DIR}/thirdparty)

add_library(GLRendererCommand GLRendererCommand.cpp)
target_include_directories(GLRendererCommand PRIVATE ${CMAKE_SOURCE_DIR}/Renderer)
target_include_directories(GLRendererCommand PRIVATE ${CMAKE_SOURCE_DIR}/thirdparty)
target_link_libraries(GLRendererCommand PUBLIC glad)