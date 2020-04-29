cmake_minimum_required (VERSION 3.11)

project(Ardor)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# external
add_subdirectory(external)

# source
add_subdirectory(source)

# example
add_subdirectory(example)