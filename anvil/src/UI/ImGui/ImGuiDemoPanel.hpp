#pragma once

// --- Anvil ---
#include "../ImGui/ImGuiPanel.hpp"



namespace anvil
{
	// This class is a layer that shows the ImGui demo window
	// - This class is NOT PERMANENT and will be deleted/moved/changed. Please
	//   avoid using this class in any code you intend to keep.
	// - Serves as a reference for rle::Layer with ImGui implementation
	// - This is also a good tool for testing ImGui implementations
	//   (i.e. Docking, Floating Windows, Rendering, etc.)
	class ImGuiDemoPanel final : public ImGuiPanel
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Constructor
		ImGuiDemoPanel();

		// Default destructor
		~ImGuiDemoPanel() = default;



	private:
		////////////////////////////////////////////////////////////////////////////////
		// - OVERRIDES -----------------------------------------------------------------

		// Inherited via Layer
		virtual void onPanelEnter() override;
		virtual void onPanelExit() override;
		virtual void onPanelUpdate(const rle::time::step_ms delta) override;

		virtual void onDraw(rle::Renderer2D& renderer) override;
		virtual void onImGuiDraw() override;
	};
}