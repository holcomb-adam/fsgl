#pragma once

// --- GLM ---
#include <glm/vec2.hpp>

// --- RLE ---
#include <RLE/Node/Node.hpp>
#include <RLE/Rendering/FrameBuffer.hpp>
#include <RLE/UI/Panel.hpp>



namespace anvil
{
	class SceneEditorPanel final : public rle::Panel
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Constructor
		SceneEditorPanel();

		// Default destructor
		~SceneEditorPanel() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - OVERRIDES -----------------------------------------------------------------
		
		// Inherited via Layer
		virtual void onPanelEnter() override;
		virtual void onPanelExit() override;
		virtual void onPanelUpdate(const rle::time::step_ms delta) override;
		virtual void onPanelDraw(rle::Renderer2D& renderer) override;



	private:
		// - Rendering -
		std::shared_ptr<rle::FrameBuffer> m_FrameBuffer;
		glm::ivec2 m_ViewportPosition = { 0, 0 };
		glm::ivec2 m_ViewportSize = { 0, 0 };
		float m_ViewportAspect = 1.0f;

		// - Scene -
		rle::Node* m_SceneNode = nullptr;
	};
}
