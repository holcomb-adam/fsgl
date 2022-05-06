#pragma once

#include <initializer_list>
#include <string>
#include <vector>

#include "Math/Shapes/Triangle.h"
#include "Renderable3D.h"



namespace rle
{
	class Mesh final : public Renderable3D
	{
	public:
		// default ctor
		Mesh() = default;

		// ctor
		// takes a list of Vector3 objects
		Mesh(const std::initializer_list<Triangle3f>& verticies);

		// default dtor
		~Mesh() = default;

		// load a mesh object from a wavefront (.obj) file
		bool load(const std::string& str);

		// get a const refernece to the underlying vector of triangles
		const std::vector<Triangle3f>& triangles() const;

		// Inherited via Renderable3D
		virtual bool render3D(
			const EngineRenderer& target,
			const Camera& camera,
			Transform transform) const override;

	private:
		std::vector<Triangle3f> m_Verticies;
	};
}

