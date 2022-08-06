#pragma once

// --- RLE ---
#include <RLE/Rendering/Camera.hpp>
#include <RLE/Rendering/IndexBuffer.hpp>
#include <RLE/Rendering/Shader.hpp>
#include <RLE/Rendering/VertexArray.hpp>
#include <RLE/Rendering/VertexBuffer.hpp>
#include <RLE/UI/Layer.h>



// RLE Forward Declarations
namespace rle
{
	class Camera;
}



namespace anvil
{
	// This class is temporary and serves to test new RLE features
	class TestingLayer final : public rle::Layer
	{
	public:
		// Inherited via Layer
		virtual void onEnter() override;
		virtual void onExit() override;
		virtual void onUpdate(const rle::time::step_ms delta) override;
		virtual void onRender(rle::Renderer& renderer) const override;



	private:
		std::unique_ptr<rle::Camera> m_Camera;
	};
}
