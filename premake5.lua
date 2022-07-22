workspace "RogueLikeEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}



-- Global directories
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
includeDirs = {}
includeDirs["GLFW"] = "RogueLikeEngine/external/GLFW/include/"



-- Setup our projects
include "RogueLikeEngine"
include "ClientApplication"
