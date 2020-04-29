# glm
#set(GLM_TEST_ENABLE OFF)
set(BUILD_SHARED_LIBS OFF)
set(BUILD_STATIC_LIBS ON)
add_subdirectory(glm/glm)

# assimp
set(ASSIMP_BUILD_TESTS OFF)
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
add_subdirectory(assimp)

# glfw
add_subdirectory(glfw)

set_property(TARGET assimp PROPERTY FOLDER "external")
set_property(TARGET glm_static PROPERTY FOLDER "external")
set_property(TARGET glfw PROPERTY FOLDER "external")
set_property(TARGET zlib PROPERTY FOLDER "external")
set_property(TARGET zlibstatic PROPERTY FOLDER "external")
set_property(TARGET IrrXML PROPERTY FOLDER "external")
set_property(TARGET UpdateAssimpLibsDebugSymbolsAndDLLs PROPERTY FOLDER "external")
set_property(TARGET uninstall PROPERTY FOLDER "external")