cmake_minimum_required(VERSION 3.1)



project(imgui)


include_directories(imgui)

add_library(${PROJECT_NAME} 
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
    imgui/imgui.cpp
    imgui/backends/imgui_impl_glfw.cpp
    imgui/backends/imgui_impl_opengl3.cpp)

# - Target Linking -
target_include_directories(${PROJECT_NAME} PRIVATE imgui)
target_link_libraries(${PROJECT_NAME} glfw)
