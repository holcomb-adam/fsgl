#pragma once

#include <initializer_list>
#include <string>
#include <vector>

#include "Math/Vector3.h"
#include "Renderable3D.h"



namespace rle
{
	class Mesh final : public Renderable3D
	{
	public:
		struct Triangle final
		{
			Vector3f p1;
			Vector3f p2;
			Vector3f p3;
		};

	public:
		// default ctor
		Mesh() = default;

		// ctor
		// takes a list of Vector3 objects
		Mesh(const std::initializer_list<Triangle>& verticies);

		// default dtor
		~Mesh() = default;

		// load a mesh object from a wavefront (.obj) file
		bool load(const std::string& str);

		// get a const refernece to the underlying vector of triangles
		const std::vector<Triangle>& triangles() const;

		// Inherited via Renderable3D
		virtual bool render3D(const EngineRenderer& target, const Camera& camera) const override;

	private:
		std::vector<Triangle> m_Verticies;
	};
}

