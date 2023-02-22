#pragma once

// RLE Library include
#include <RLE/UI/Layer.hpp>



namespace anvil
{
	// This class is a layer that shows the ImGui demo window
	// - This class is NOT PERMANENT and will be deleted/moved/changed. Please
	//   avoid using this class in any code you intend to keep.
	// - Serves as a reference for rle::Layer with ImGui implementation
	// - This is also a good tool for testing ImGui implementations
	//   (i.e. Docking, Floating Windows, Rendering, etc.)
	class ImGuiLayer final : public rle::Layer
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Constructor
		ImGuiLayer();

		// Default destructor
		~ImGuiLayer() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - OVERRIDES -----------------------------------------------------------------

		// Inherited via Layer
		virtual void onEnter() override;
		virtual void onExit() override;
		virtual void onUpdate(const rle::time::step_ms delta) override;
		virtual void onRender(rle::Renderer& renderer) const override;
	};
}