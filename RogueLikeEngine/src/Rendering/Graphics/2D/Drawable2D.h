#pragma once



namespace rle
{
	// EngineRenderer forward declarations
	class EngineRenderer;



	// a class that will allow an object to be drawn to the screen
	class Drawable2D
	{
	public:
		// default ctor
		Drawable2D() = default;

		// virtual default dtor
		virtual ~Drawable2D() = default;

		// this will define how the derived object should be rendered
		virtual bool draw(const EngineRenderer& renderer) const = 0;
	};
}
