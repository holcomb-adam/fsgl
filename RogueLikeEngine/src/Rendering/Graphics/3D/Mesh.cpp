#include "Mesh.h"

#include <fstream>
#include <sstream>

#include "Camera.h"
#include "Log/Log.h"
#include "Math/Constants.h"
#include "Rendering/EngineRenderer.h"

rle::Mesh::Mesh(const std::initializer_list<Triangle3f>& verticies) :
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

		// check what data we are reading
		if (delim == "v") // vertex delimiter
		{
			Vector3f v;
			iss >> v.x >> v.y >> v.z;
			verts.push_back(std::move(v));
		}
		else if (delim == "f")
		{
			// get the face definitions
			std::vector<std::size_t> f;
			std::string vb;
			for (std::size_t i = 0; iss >> vb; i++)
				f.push_back(std::stoi(vb.substr(0, vb.find_first_of('/'))));

			// define the face
			// determine if we are working with triangles or quads
			switch (f.size())
			{
			case math::constants::TRI_VERTS: // working with triangles
				m_Verticies.push_back({
					verts[f[0] - 1],
					verts[f[1] - 1],
					verts[f[2] - 1] });
				break;

			case math::constants::QUAD_VERTS: // working with quads
				m_Verticies.push_back({
					verts[f[0] - 1],
					verts[f[1] - 1],
					verts[f[2] - 1] });
				m_Verticies.push_back({
					verts[f[2] - 1],
					verts[f[3] - 1],
					verts[f[0] - 1] });
				break;

			default:
				RLE_LOG_OUT(log::ERR, "Loading wavefront (.obj), recieved invalid amount of verticies!"
					"RLE meshes only support 3 and 4 vertex faces!");
				return false;
				break;
			}
		}
	}

	// close file
	ifs.close();

	return true;
}

const std::vector<rle::Triangle3f>& rle::Mesh::triangles() const
{
	return m_Verticies;
}

bool rle::Mesh::render3D(const EngineRenderer& target, const Camera& camera, Transform transform) const
{
	// our projected triangle
	Triangle2f prj;

	// loop for each of the triangles in the mesh
	for (const auto& tri : m_Verticies)
	{
		// calculate the projection of the points
		const auto projected = camera.project3D(target, tri, prj, transform);

		// draw triangles from the projection points
		target.drawLine(prj[0], prj[1], color_constants::WHITE);
		target.drawLine(prj[1], prj[2], color_constants::WHITE);
		target.drawLine(prj[0], prj[2], color_constants::WHITE);
	}

	return true;
}
