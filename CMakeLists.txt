# Rogue-like Engine CMake file

cmake_minimum_required(VERSION 3.1)



# Ensure git submodules are initialized
find_package(Git QUIET)
if (GIT_FOUND AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.git")
    option(RLE_CHECK_GITSUBMODULES "Check submodule statuses during build" ON)
    if (RLE_CHECK_GITSUBMODULES)
        message(STATUS "Updating git submodules...")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if (NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()



# Setup glad library before RLE project because for whatever reason glad will 
# hijack the root cmake project causing linking issues
include(external/glad/cmake/CMakeLists.txt)
glad_add_library(glad_core45 STATIC API gl:core=4.5)



# Root project for cmake
project(rogue-like-engine LANGUAGES CXX)

message(STATUS "Building rogue-like engine...")



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
option(RLE_BUILD_ANVIL "Build the rle editor Anvil" ON)



# --- BUILD EXTERNAL PROJECTS --------------------------------------------------

message(STATUS "Building rle dependencies...")

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



# --- BUILD RLE ----------------------------------------------------------------

# Get project include files
file(GLOB_RECURSE RLE_INCLUDE_FILES include/*.hpp)
file(GLOB         RLE_SOURCE_FILES  src/*.cpp)

# Create library
message(STATUS "Creating rle object library...")
add_library(${PROJECT_NAME} STATIC ${RLE_SOURCE_FILES})

# Set target options
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_precompile_headers(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include/RLEpch.hpp)
target_link_libraries(${PROJECT_NAME} spdlog)
target_link_libraries(${PROJECT_NAME} glad_core45)
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} glm)

# Build anvil editor
if (RLE_BUILD_ANVIL)
    file(GLOB_RECURSE RLE_ANVIL_SOURCE_FILES anvil/src/**.cpp)

    message(STATUS "Building rle-anvil dependencies...")
    add_subdirectory(anvil/external/imgui)

    message(STATUS "Building rle-anvil...")
    add_executable(rle-anvil ${RLE_ANVIL_SOURCE_FILES})
    target_include_directories(rle-anvil PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
    target_include_directories(rle-anvil PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/external/glm)
    target_include_directories(rle-anvil PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/anvil/external/imgui)
    target_include_directories(rle-anvil PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/anvil/external/imgui/imgui)
    target_link_libraries(rle-anvil rogue-like-engine)
    target_link_libraries(rle-anvil imgui)
endif()
