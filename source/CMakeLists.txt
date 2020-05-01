# include
include_directories(${CMAKE_SOURCE_DIR}/external/assimp/include)
include_directories(${CMAKE_SOURCE_DIR}/external/glad/include)
include_directories(${CMAKE_SOURCE_DIR}/external/glfw/include)
include_directories(${CMAKE_SOURCE_DIR}/external/glm)
include_directories(${CMAKE_SOURCE_DIR}/external)
include_directories(${CMAKE_SOURCE_DIR}/source/Util/Log)

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

# windows platform
set(WINDOWS_SRCS
	${CMAKE_SOURCE_DIR}/source/Platform/Windows/WinApplication.h
	${CMAKE_SOURCE_DIR}/source/Platform/Windows/WinApplication.cpp
	${CMAKE_SOURCE_DIR}/source/Platform/Windows/WinWindows.h
	${CMAKE_SOURCE_DIR}/source/Platform/Windows/WinWindows.cpp
)

# log
set(LOG_SRCS
	${CMAKE_SOURCE_DIR}/source/Util/Log/Log.h
	${CMAKE_SOURCE_DIR}/source/Util/Log/Log.cpp
)

# group
source_group(RenderAPI\\API FILES ${API_SRCS})
source_group(RenderAPI\\OGL FILES ${OGL_SRCS})
source_group(Platform\\Windows FILES ${WINDOWS_SRCS})
source_group(Util\\Log FILES ${LOG_SRCS})

add_library(Ardor SHARED
	${API_SRCS}
	${OGL_SRCS}
	${WINDOWS_SRCS}
	${LOG_SRCS}
)

# link
target_link_libraries(Ardor glm_static)
target_link_libraries(Ardor assimp)
target_link_libraries(Ardor glfw)