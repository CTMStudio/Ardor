add_executable(Null
    Null.cpp
)
include_directories(${CMAKE_SOURCE_DIR}/external)
target_link_libraries(Null glfw)