#pragma once

// RLE Library include
#include <RLE/UI/Layer.h>



namespace anvil
{
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
		virtual void onRender() const override;
	};
}