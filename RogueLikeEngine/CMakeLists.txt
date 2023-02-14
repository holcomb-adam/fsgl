cmake_minimum_required(VERSION 3.1)

project(RogueLikeEngine LANGUAGES CXX)

# - Project Source Files -
file(GLOB_RECURSE PRJ_SOURCE src/*.cpp)

# - Include Directories -
include_directories(${PROJECT_SOURCE_DIR}/external/GLAD/include) # - External dir
include_directories(${GLFW_INCLUDE})

add_library(${PROJECT_NAME} STATIC ${PRJ_SOURCE})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src) # ------------------- RLE source dir
target_precompile_headers(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src/RLEpch.hpp)
target_link_libraries(${PROJECT_NAME})

# Expose RLE public includes
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/src
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
