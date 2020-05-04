add_executable(Null
    Null.cpp
	../IApplication.h
	../IApplication.cpp
)
include_directories(${CMAKE_SOURCE_DIR}/source)
include_directories(${CMAKE_SOURCE_DIR}/source/Util/Log)
include_directories(${CMAKE_SOURCE_DIR}/external)