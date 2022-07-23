-- Setup the Rogue-Like Engine project
project "RogueLikeEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "RLEpch.h"
	pchsource "src/RLEpch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp",

		-- Add GLAD source to the project to compile
		"external/GLAD/src/glad.c"
	}

	includedirs
	{
		"src",
		"%{wks.location}/external/spdlog/include",
		"external/GLFW/include",
		"external/GLAD/include"
	}

	links
	{
		"external/GLFW/lib/glfw3.lib",
		"opengl32.lib"
	}

	filter "files:external/GLAD/src/glad.c"
		flags { "NoPCH" }

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"RLE_OS_WIN64"
		}

	filter "configurations:Debug"
		defines "RLE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "RLE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "RLE_DIST"
		runtime "Release"
		optimize "on"
