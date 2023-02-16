#pragma once



namespace rle
{
	// RLE Forward Declarations
	class Renderer;



	// This is the main rendering facility used by RLE. All objects that need to be
	// rendered to the screen (rle::VertexArray aside) must inherit from this class.
	class Renderable
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------
		
		// Default constructor
		Renderable() = default;

		// Virtual default constructor
		// - Note: While this is virtual, deleting from this class is not recommended!
		virtual ~Renderable() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - VIRTUALS ------------------------------------------------------------------

		// Called before the object is rendered via "Renderable::onRender"
		inline virtual void onPreRender(Renderer& target) {}

		// Called after the object has been rendered via "Renderable::onRender"
		inline virtual void onPostRender(Renderer& target) {}



		////////////////////////////////////////////////////////////////////////////////
		// - PURE VIRTUALS -------------------------------------------------------------

		// Called when an object is being renderer
		// - 'target':    The render target that the object is being drawn to
		virtual void onRender(Renderer& target) const = 0;
	};
}
