# include
include_directories(${CMAKE_SOURCE_DIR}/external/assimp/include)
include_directories(${CMAKE_SOURCE_DIR}/external/glad/include)
include_directories(${CMAKE_SOURCE_DIR}/external/glfw/include)
include_directories(${CMAKE_SOURCE_DIR}/external/glm)

# ogl src
set (OGL_SRCS
    ${CMAKE_SOURCE_DIR}/external/glad/src/glad.c
)

# group
source_group(RenderAPI\\OGL FILES ${OGL_SRCS})

add_library(Ardor SHARED
    ${OGL_SRCS}
)

# link
target_link_libraries(Ardor glm_static)
target_link_libraries(Ardor assimp)