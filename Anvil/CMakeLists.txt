cmake_minimum_required(VERSION 3.1)

project(Anvil LANGUAGES CXX)

# - Project Source Files -
file(GLOB_RECURSE PRJ_SOURCE src/*.cpp)
file(GLOB IMGUI_SRC external/ImGui/*.cpp)

# - Include Directories -
include_directories(${RogueLikeEngine_INCLUDE_DIRS})
include_directories(../external/glm)
include_directories(external/ImGui)
include_directories(external/ImGui/ImGui)

# Create the executable
add_executable(${PROJECT_NAME} ${PRJ_SOURCE} ${IMGUI_SRC})

# - Target Linking -
target_include_directories(${PROJECT_NAME} PRIVATE src)
target_link_libraries(${PROJECT_NAME} RogueLikeEngine)
target_link_libraries(${PROJECT_NAME} ImGui)
