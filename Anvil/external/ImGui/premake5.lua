project "ImGui"
	kind "StaticLib"
	language "C++"
    cppdialect "C++17"
    staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"ImGui/imconfig.h",
		"ImGui/imgui.cpp",
		"ImGui/imgui.h",
        "ImGui/imgui_demo.cpp",
		"ImGui/imgui_draw.cpp",
		"ImGui/imgui_internal.h",
        "ImGui/imgui_tables.cpp",
		"ImGui/imgui_widgets.cpp",
		"ImGui/imstb_rectpack.h",
		"ImGui/imstb_textedit.h",
		"ImGui/imstb_truetype.h",

        -- Include the ImGui backends
        "ImGui/backends/imgui_impl_glfw.cpp",
        "ImGui/backends/imgui_impl_glfw.h",
        "ImGui/backends/imgui_impl_opengl3.cpp",
        "ImGui/backends/imgui_impl_opengl3.h"
	}

    includedirs
    {
        "ImGui",

		-- Allow ImGui to see GLFW
		"%{lib_includes.GLFW}"
    }

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"