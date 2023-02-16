#pragma once

// RLE Library includes
#include <RLE/Core/Engine.hpp>
#include <RLE/UI/Layer.hpp>



namespace anvil
{
	class DockingLayer final : public rle::Layer
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Constructor
		DockingLayer();

		// Default destructor
		~DockingLayer() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - OVERRIDES -----------------------------------------------------------------

		// Inherited via Layer
		virtual void onEnter() override;
		virtual void onExit() override;
		virtual void onUpdate(const rle::time::step_ms delta) override;
		virtual void onRender(rle::Renderer& renderer) const override;



	private:
		rle::Engine* m_Engine = nullptr;
	};
}
