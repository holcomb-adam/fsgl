cmake_minimum_required(VERSION 3.1)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE ON)

# Add projects to the CMake list
# - External projects -
add_subdirectory(external/glm)
add_subdirectory(external/spdlog)

# - Rogue-Like Engine Library -
add_subdirectory(RogueLikeEngine)

# - Anvil Editor 
add_subdirectory(Anvil)
