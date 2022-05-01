#pragma once

#include "Transform.h"



namespace rle
{
	// rle forward declarations
	class Camera;
	class EngineRenderer;



	// allows the EngineRenderer
	class Renderable3D
	{
	public:
		// default ctor
		Renderable3D() = default;

		// virtual default dtor
		virtual ~Renderable3D() = default;

		// performs 3D rendering operations on the object
		virtual bool render3D(const EngineRenderer&, const Camera&, Transform transform) const = 0;
	};
}