cmake_minimum_required(VERSION 3.1)

# Root project for cmake
project(RLE)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE ON)

# Check for git
find_package(Git QUIET)
if (GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    option(GIT_SUBMODULE "Check and update submodules udring build" ON)
    if (GIT_SUBMODULE)
        message(STATUS "Updating Submodules...")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if (NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

# Add projects to build to the CMake list
# - External projects -
add_subdirectory(external/spdlog)
add_subdirectory(external/glm)

# --- Setup GLFW ---
set(GLFW_BUILD_EXAMPLES OFF CAHCE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory(RogueLikeEngine/external/glfw)

add_subdirectory(Anvil/external/ImGui)

# --- Setup RLE ---
add_subdirectory(RogueLikeEngine)

# - Anvil Editor -
add_subdirectory(Anvil)
