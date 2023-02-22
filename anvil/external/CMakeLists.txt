cmake_minimum_required(VERSION 3.1)



project(ImGui)


include_directories(ImGui)

add_library(${PROJECT_NAME} 
    ImGui/imgui_demo.cpp
    ImGui/imgui_draw.cpp
    ImGui/imgui_tables.cpp
    ImGui/imgui_widgets.cpp
    ImGui/imgui.cpp
    ImGui/backends/imgui_impl_glfw.cpp
    ImGui/backends/imgui_impl_opengl3.cpp)

# - Target Linking -
target_include_directories(${PROJECT_NAME} PRIVATE ImGui)
target_link_libraries(${PROJECT_NAME} glfw)
