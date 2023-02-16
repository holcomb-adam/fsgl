# Rogue-like Engine CMake file

cmake_minimum_required(VERSION 3.1)



# Root project for cmake
project(rogue-like-engine LANGUAGES CXX)

# Debug
message(STATUS "Building rogue-like engine...")



# --- SETUP CMAKE / CONFIGURE COMPILER -----------------------------------------

# Debugging information
set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)

# Set CMake build configuration
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

# Set C++ version standard
if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()



# --- USER OPTIONS -------------------------------------------------------------

# API
option(RLE_API_LOGGING   "Enable logging with the RLE lib"      ON)
option(RLE_API_WINDOWING "Enable windowing with the RLE lib"    ON)



# --- BUILD EXTERNAL PROJECTS --------------------------------------------------

# spdlog
add_subdirectory(external/spdlog)

# glad
add_subdirectory(external/glad/cmake)

# glm
add_subdirectory(external/glm)

# GLFW
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory(external/glfw)



# --- BUILD RLE ----------------------------------------------------------------

# Get project include files
file(GLOB_RECURSE RLE_INCLUDE_FILES include)
file(GLOB RLE_SOURCE_FILES src)

# Create library
add_library(${PROJECT_NAME} STATIC ${RLE_SOURCE_FILES})

# Set target options
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
#target_precompile_headers(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include/RLEpch.hpp)
target_link_libraries(${PROJECT_NAME} spdlog)
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} glm)
