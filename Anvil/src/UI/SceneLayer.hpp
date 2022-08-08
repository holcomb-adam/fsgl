#pragma once

// --- RLE ---
#include <RLE/Rendering/Camera.hpp>
#include <RLE/Rendering/Framebuffer.hpp>
#include <RLE/UI/Layer.h>



namespace anvil
{
	class SceneLayer final : public rle::Layer
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Constructor
		SceneLayer();

		// Default destructor
		~SceneLayer() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - OVERRIDES -----------------------------------------------------------------
		
		// Inherited via Layer
		virtual void onEnter() override;
		virtual void onExit() override;
		virtual void onUpdate(const rle::time::step_ms delta) override;
		virtual void onRender(rle::Renderer& renderer) const override;



	private:
		// - Rendering -
		std::shared_ptr<rle::FrameBuffer> m_FrameBuffer;
		glm::ivec2 m_ViewportPosition = { 0, 0 };
		glm::ivec2 m_ViewportSize = { 0, 0 };
		float m_ViewportAspect = 1.0f;

		// - Scene -
		std::unique_ptr<rle::Camera> m_Camera;
		double m_CameraSpeed = 0.02;
	};
}
