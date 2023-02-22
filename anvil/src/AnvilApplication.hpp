#pragma once

// --- RLE ---
#include <RLE.hpp>
#include <RLE/Rendering/Shader.hpp>

// --- Anvil ---
#include "UI/ImGui/ImGuiRenderer.hpp"



namespace anvil
{
	class AnvilApplication final : public rle::Engine
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Constructor
		AnvilApplication();

		// Default destructor
		~AnvilApplication() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - OVERRIDES -----------------------------------------------------------------

		// Inherited via rle::Engine
		virtual std::size_t init() override;
		virtual void onUpdate(const rle::time::step_ms delta) override;
		virtual void onPreRender() override;
		virtual void onRender(rle::Renderer& renderer) override;
		virtual void onPostRender() override;



	private:
		ImGuiRenderer m_ImGuiRenderer;
	};
}
