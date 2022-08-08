#pragma once

// --- RLE ---
#include <RLE/Rendering/Camera.hpp>
#include <RLE/Rendering/FrameBuffer.hpp>
#include <RLE/UI/Layer.h>



// RLE Forward Declarations
namespace rle
{
	class Camera;
}



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



	private:
		std::unique_ptr<rle::Camera> m_Camera;
		std::shared_ptr<rle::FrameBuffer> m_FBO;

		glm::u32vec2 m_ViewportPosition = { 0, 0 };
		glm::u64vec2 m_ViewportSize = { 0, 0 };
	};
}
