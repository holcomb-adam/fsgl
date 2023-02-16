#pragma once

// --- RLE ---s
#include <RLE/UI/Layer.hpp>



namespace anvil
{
	// This class is temporary and serves to test new RLE Layer features
	class TestingLayer final : public rle::Layer
	{
	public:
		// Default constructor
		TestingLayer();

		// Inherited via Layer
		virtual void onEnter() override;
		virtual void onExit() override;
		virtual void onUpdate(const rle::time::step_ms delta) override;
		virtual void onRender(rle::Renderer& renderer) const override;
	};
}
