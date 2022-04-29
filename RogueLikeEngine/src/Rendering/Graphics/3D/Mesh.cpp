#include "Mesh.h"

#include <fstream>
#include <sstream>

#include "Camera.h"
#include "Math/Constants.h"
#include "Rendering/EngineRenderer.h"

rle::Mesh::Mesh(const std::initializer_list<Triangle>& verticies) :
	m_Verticies(verticies)
{

}

bool rle::Mesh::load(const std::string& str)
{
	// clear the current verticies
	m_Verticies.clear();

	// open a file stream to access the file
	std::ifstream ifs;
	ifs.open(str);

	// check if the file opened properly
	if (!ifs.is_open())
		return false;

	// buffer of verticies to define the mesh
	std::vector<Vector3f> verts;

	// read the verticies
	while (!ifs.eof())
	{
		// get the line
		std::string line;
		std::getline(ifs, line);

		// open a string stream
		std::istringstream iss(line);

		// get the line delimiter
		std::string delim;
		iss >> delim;

		// check if we are reading vertex data
		if (delim == "v") // vertex delimiter
		{
			Vector3f v;
			iss >> v.x >> v.y >> v.z;
			verts.push_back(std::move(v));
		}
	}

	// close file
	ifs.close();

	// load the verticies into the object
	// verticies are stored in a counterclockwise fashion so we
	// loop through the verticies backwards
	for (std::size_t i = verts.size() - 1; i > 1; i--)
	{
		Triangle tri;
		tri.p1 = verts[i];
		tri.p2 = verts[i - 1];
		tri.p3 = verts[i - 2];

		m_Verticies.push_back(std::move(tri));
	}

	return true;
}

const std::vector<rle::Mesh::Triangle>& rle::Mesh::triangles() const
{
	return m_Verticies;
}

bool rle::Mesh::render3D(const EngineRenderer& target, const Camera& camera, Transform transform) const
{
	// our vector point buffers
	Vector2f p1;
	Vector2f p2;
	Vector2f p3;

	// loop for each of the triangles in the mesh
	for (const auto& tri : m_Verticies)
	{
		// calculate the projection of the points
		camera.project3D(target, tri.p1, p1, transform);
		camera.project3D(target, tri.p2, p2, transform);
		camera.project3D(target, tri.p3, p3, transform);

		// draw triangles from the projection points
		target.drawLine(p1, p2, color_constants::WHITE);
		target.drawLine(p2, p3, color_constants::WHITE);
		target.drawLine(p1, p3, color_constants::WHITE);
	}

	return true;
}
