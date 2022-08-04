workspace "RogueLikeEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}



-- Common build output directory
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Global directories for projects
libs = {}
libs["GLAD"] = "%{wks.location}/RogueLikeEngine/external/GLAD"
libs["GLFW"] = "%{wks.location}/RogueLikeEngine/external/GLFW"
libs["glm"] = "%{wks.location}/external/glm"
libs["ImGui"] = "%{wks.location}/Anvil/external/ImGui"
libs["spdlog"] = "%{wks.location}/external/spdlog"

-- Global directories for include paths
lib_includes = {}
lib_includes["GLAD"] = "%{libs.GLAD}/include"
lib_includes["GLFW"] = "%{libs.GLFW}/include"
lib_includes["glm"] = "%{libs.glm}"
lib_includes["ImGui"] = "%{libs.ImGui}"
lib_includes["spdlog"] = "%{libs.spdlog}/include"




-- Setup our projects
group "Dependencies"
	include "Anvil/external/ImGui"

group ""

include "RogueLikeEngine"
include "Anvil"