#include "fsgl_pch.hpp"
#include "fsgl/Resources/Geometry.hpp"

// --- fsgl ---
#include "fsgl/Debug/Log.hpp"



fsgl::Geometry::Geometry() : 
	Resource(true, "", "")
{

}

fsgl::Geometry::Geometry(const std::vector<glm::vec2>& vertices) : 
	Resource(true, "","")
{
	load(vertices.data(), vertices.size());
}

fsgl::Geometry::Geometry(const std::string& path) :
	Resource(false, "", path)
{
	if (!load(path))
		FSGL_CORE_WARN("Node \"{0}\" failed to load from path \"{1}\"", name(), path);
}

void fsgl::Geometry::load(const glm::vec2* data, const std::size_t n)
{
	m_Vertices.clear();

	for (std::size_t i = 0; i < n; i++)
		m_Vertices.push_back(data[i]);
}

bool fsgl::Geometry::load(const std::string& path)
{
	return false;
}

std::size_t fsgl::Geometry::count() const
{
	return m_Vertices.size();
}

const glm::vec2* fsgl::Geometry::data() const
{
	return m_Vertices.data();
}

std::vector<std::uint32_t> fsgl::Geometry::indices() const
{
	std::vector<std::uint32_t> vec;
	
	/// @bug Right now, this assumes shapes are in a triangle
	///      array. Eventually this needs rectification. Due to this
	///      current limitation, this check is in place to ensure any
	///      geometry satisfies the triangle array requirement.
	if (m_Vertices.size() % 3 != 0)
	{
		FSGL_CORE_WARN(
			"Geometry has invalid geometry. Expected a multiple of 3, has {0}.",
			m_Vertices.size());
		return vec;
	}

	for (std::uint32_t i = 0; i < m_Vertices.size(); i++)
		vec.push_back(i);

	return vec;
}
