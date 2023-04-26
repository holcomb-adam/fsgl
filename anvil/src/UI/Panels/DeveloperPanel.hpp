#pragma once

// --- Standard ---
#include <vector>

// --- Anvil ---
#include "../ImGui/ImGuiPanel.hpp"



namespace anvil
{
	// Will provide debugging information through ImGui
	class DeveloperPanel : public ImGuiPanel
	{
		static constexpr std::size_t FRAME_TIME_COUNTER_MAX_SIZE = 300;



	public:
		/// @brief 
		DeveloperPanel();

		// Inherited via Layer
		virtual void onPanelEnter() override;
		virtual void onPanelExit() override;
		virtual void onPanelUpdate(const rle::time::step_ms delta) override;

		virtual void onDraw(rle::Renderer2D& renderer) override;
		virtual void onImGuiDraw() override;



	private: 
		rle::time::step_sec m_Timer;
		
		std::vector<float> m_FrameTimeCounter;
		float m_AverageFrameTime = 0.0;

		bool m_Open = true;
		bool m_FramePlotPaused = false;
	};
}
