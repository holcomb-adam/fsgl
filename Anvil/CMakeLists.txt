cmake_minimum_required(VERSION 3.1)

project(Anvil LANGUAGES CXX)

file(GLOB_RECURSE PRJ_SOURCE src/*.cpp)

#message(STATUS "${PRJ_SOURCE}")

include_directories(${RogueLikeEngine_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${PRJ_SOURCE})

target_link_libraries(${PROJECT_NAME} RogueLikeEngine)
