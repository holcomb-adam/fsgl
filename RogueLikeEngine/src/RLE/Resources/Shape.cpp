#include "RLEpch.hpp"
#include "Shape.hpp"

// --- RLE ---
#include "RLE/Debug/Log.hpp"



rle::Shape::Shape() : 
	Resource(true, "", "")
{

}

rle::Shape::Shape(const std::vector<glm::vec2>& poly) : 
	Resource(true, "","")
{
	load(poly.data(), poly.size());
}

rle::Shape::Shape(const std::string& path) :
	Resource(false, "", path)
{
	if (!load(path))
		RLE_CORE_WARN("Node \"{0}\" failed to load from path \"{1}\"", name(), path);
}

void rle::Shape::load(const glm::vec2* data, const std::size_t n)
{
	m_Polygon.clear();

	for (std::size_t i = 0; i < n; i++)
		m_Polygon.push_back(data[i]);
}

bool rle::Shape::load(const std::string& path)
{
	return false;
}

std::size_t rle::Shape::count() const
{
	return m_Polygon.size();
}

const glm::vec2* rle::Shape::data() const
{
	return m_Polygon.data();
}

std::vector<std::uint32_t> rle::Shape::indices() const
{
	std::vector<std::uint32_t> vec;
	
	// Note: Right now, this assumes shapes are in a triangle
	//       array. Eventually this needs rectification. Due to this
	//       current limitation, this check is in place to ensure any
	//       geometry satisfies the triangle array requirement.
	if (m_Polygon.size() % 3 != 0)
	{
		RLE_CORE_WARN(
			"Shape has invalid geometry. Expected a multiple of 3, has {0}.",
			m_Polygon.size());
		return vec;
	}

	for (std::uint32_t i = 0; i < m_Polygon.size(); i++)
		vec.push_back(i);

	return vec;
}
