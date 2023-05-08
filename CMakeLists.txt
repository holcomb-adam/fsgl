# fsgl Cmake file

cmake_minimum_required(VERSION 3.1)



# Ensure git submodules are initialized
find_package(Git QUIET)
if (GIT_FOUND AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.git")
    option(FSGL_CHECK_GITSUBMODULES "Check submodule statuses during build" ON)
    if (FSGL_CHECK_GITSUBMODULES)
        message(STATUS "Updating git submodules...")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if (NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()



# Setup glad library before fsgl project because for whatever reason glad will 
# hijack the root cmake project causing linking issues
include(external/glad/cmake/CMakeLists.txt)
glad_add_library(glad_core45 STATIC API gl:core=4.5)



# Root project for cmake
message(STATUS "Building fsgl project...")
project(fsgl LANGUAGES CXX)



# --- SETUP CMAKE / CONFIGURE COMPILER -----------------------------------------

# Debugging information
set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)

# Set CMake build configuration
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set C++ version standard
if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()



# --- USER OPTIONS -------------------------------------------------------------

# API



# --- BUILD EXTERNAL PROJECTS --------------------------------------------------

message(STATUS "Building fsgl dependencies...")

# spdlog
add_subdirectory(external/spdlog)

# glm
add_subdirectory(external/glm)

# glfw
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS    OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS     OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL        OFF CACHE INTERNAL "Generate installation target")
add_subdirectory(external/glfw)



# --- BUILD FSGL ----------------------------------------------------------------

# Get project include files
file(GLOB_RECURSE FSGL_INCLUDE_FILES include/*.hpp)
file(GLOB         FSGL_SOURCE_FILES  src/*.cpp)

# Create library
message(STATUS "Creating fsgl object library...")
add_library(${PROJECT_NAME} STATIC ${FSGL_SOURCE_FILES})

# Set target options
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_precompile_headers(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include/fsgl_pch.hpp)
target_link_libraries(${PROJECT_NAME} spdlog)
target_link_libraries(${PROJECT_NAME} glad_core45)
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} glm)
