#pragma once

// RLE Library include
#include "Layer.h"



namespace rle
{
	class ImGuiLayer final : public Layer
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
		virtual void onUpdate(const float delta) override;
	};
}