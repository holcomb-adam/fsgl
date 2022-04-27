#include "Mesh.h"

#include <fstream>

#include "Camera.h"
#include "Math/Constants.h"
#include "Rendering/EngineRenderer.h"

rle::Mesh::Mesh(const std::initializer_list<Triangle>& verticies) :
	m_Verticies(verticies)
{

}

bool rle::Mesh::load(const std::string& str)
{
	// open a file stream to access the file
	std::ifstream ifs;
	ifs.open(str);

	// check if the file opened properly
	if (!ifs.is_open())
		return false;

	// read the verticies
	std::string token;
	while (ifs >> token)
		if (token == "v") // geometric vertex delimiter
		{
			// verticies buffer
			float verts[3] = {};

			// load vertex data
			for (std::size_t i = 0; i < 3; i++)
			{
				ifs >> token;
				verts[i] = std::stof(token);
			}
		}

	// close file
	ifs.close();

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
