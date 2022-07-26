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
libs["ImGui"] = "%{wks.location}/RogueLikeEngine/external/ImGui"
libs["spdlog"] = "%{wks.location}/external/spdlog"

-- Global directories for include paths
lib_includes = {}
lib_includes["GLAD"] = "%{libs.GLAD}/include/"
lib_includes["GLFW"] = "%{libs.GLFW}/include/"
lib_includes["ImGui"] = "%{libs.ImGui}/include/"
lib_includes["spdlog"] = "%{libs.spdlog}/include/"



-- Setup our projects
include "RogueLikeEngine/external/ImGui"
include "RogueLikeEngine"
include "ClientApplication"