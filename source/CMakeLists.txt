# include
include_directories(${CMAKE_SOURCE_DIR}/external/assimp/include)
include_directories(${CMAKE_SOURCE_DIR}/external/glad/include)
include_directories(${CMAKE_SOURCE_DIR}/external/glfw/include)
include_directories(${CMAKE_SOURCE_DIR}/external/glm)
include_directories(${CMAKE_SOURCE_DIR}/external)
include_directories(${CMAKE_SOURCE_DIR}/source/Util/Log)

# api
set(API_SRCS
	Graphics/API/IndexBuffer.h
	Graphics/API/RenderCommon.h
	Graphics/API/RenderContext.h
	Graphics/API/Shader.h
	Graphics/API/Texture.h
	Graphics/API/VertexBuffer.h
)

# ogl src
set (OGL_SRCS
    ${CMAKE_SOURCE_DIR}/external/glad/src/glad.c
	Graphics/OGL/OGLIndexBuffer.h
	Graphics/OGL/OGLIndexBuffer.cpp
	Graphics/OGL/OGLRenderContext.h
	Graphics/OGL/OGLRenderContext.cpp
	Graphics/OGL/OGLShader.h
	Graphics/OGL/OGLShader.cpp
	Graphics/OGL/OGLTexture.h
	Graphics/OGL/OGLTexture.cpp
	Graphics/OGL/OGLVertexBuffer.h
	Graphics/OGL/OGLVertexBuffer.cpp
)

# windows platform
set(WINDOWS_SRCS
	Render/RenderWindow.h
	Render/RenderWindow.cpp
)

# log
set(LOG_SRCS
	Util/Log/Log.h
	Util/Log/Log.cpp
)

# engie
set(ENGINE_SRCS
	Engine.h
	EngineImp.h
	EngineImp.cpp
)

# group
source_group(Graphics\\API FILES ${API_SRCS})
source_group(Graphics\\OGL FILES ${OGL_SRCS})
source_group(Render FILES ${WINDOWS_SRCS})
source_group(Util\\Log FILES ${LOG_SRCS})
source_group(Engine FILES ${ENGINE_SRCS})

# macros definition
add_definitions("-DDLL_EXPORTS")

add_library(Ardor SHARED
	${API_SRCS}
	${OGL_SRCS}
	${WINDOWS_SRCS}
	${LOG_SRCS}
	${ENGINE_SRCS}
)

# link
target_link_libraries(Ardor glm_static)
target_link_libraries(Ardor assimp)
target_link_libraries(Ardor glfw)