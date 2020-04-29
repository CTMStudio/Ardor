# include
include_directories(${CMAKE_SOURCE_DIR}/external/assimp/include)
include_directories(${CMAKE_SOURCE_DIR}/external/glad/include)
include_directories(${CMAKE_SOURCE_DIR}/external/glfw/include)
include_directories(${CMAKE_SOURCE_DIR}/external/glm)

# api
set(API_SRCS
	${CMAKE_SOURCE_DIR}/source/RenderAPI/API/IndexBuffer.h
	${CMAKE_SOURCE_DIR}/source/RenderAPI/API/RenderCommon.h
	${CMAKE_SOURCE_DIR}/source/RenderAPI/API/RenderContext.h
	${CMAKE_SOURCE_DIR}/source/RenderAPI/API/Shader.h
	${CMAKE_SOURCE_DIR}/source/RenderAPI/API/Texture.h
	${CMAKE_SOURCE_DIR}/source/RenderAPI/API/VertexBuffer.h
)

# ogl src
set (OGL_SRCS
    ${CMAKE_SOURCE_DIR}/external/glad/src/glad.c
	${CMAKE_SOURCE_DIR}/source/RenderAPI/OGL/OGLIndexBuffer.h
	${CMAKE_SOURCE_DIR}/source/RenderAPI/OGL/OGLIndexBuffer.cpp
	${CMAKE_SOURCE_DIR}/source/RenderAPI/OGL/OGLRenderContext.h
	${CMAKE_SOURCE_DIR}/source/RenderAPI/OGL/OGLRenderContext.cpp
	${CMAKE_SOURCE_DIR}/source/RenderAPI/OGL/OGLShader.h
	${CMAKE_SOURCE_DIR}/source/RenderAPI/OGL/OGLShader.cpp
	${CMAKE_SOURCE_DIR}/source/RenderAPI/OGL/OGLTexture.h
	${CMAKE_SOURCE_DIR}/source/RenderAPI/OGL/OGLTexture.cpp
	${CMAKE_SOURCE_DIR}/source/RenderAPI/OGL/OGLVertexBuffer.h
	${CMAKE_SOURCE_DIR}/source/RenderAPI/OGL/OGLVertexBuffer.cpp
)

# group
source_group(RenderAPI\\API FILES ${API_SRCS})
source_group(RenderAPI\\OGL FILES ${OGL_SRCS})

add_library(Ardor SHARED
	${API_SRCS}
	${OGL_SRCS}
)

# link
target_link_libraries(Ardor glm_static)
target_link_libraries(Ardor assimp)