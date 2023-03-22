#include "DeveloperPanel.hpp"

// --- RLE ---
#include <imgui/imgui.h>



anvil::DeveloperPanel::DeveloperPanel() :
	rle::Panel("Developer Panel")
{

}

void anvil::DeveloperPanel::onPanelEnter()
{
	m_FrameTimeCounter.resize(FRAME_TIME_COUNTER_MAX_SIZE, 0.0f);
}

void anvil::DeveloperPanel::onPanelExit()
{

}

void anvil::DeveloperPanel::onPanelUpdate(const rle::time::step_ms delta)
{
	// Increment the timer
	m_Timer += delta;

	// Increment our frame counter
	if (!m_FramePlotPaused)
	{
		m_FrameTimeCounter.push_back(static_cast<float>(delta.count()));

		if (m_FrameTimeCounter.size() > FRAME_TIME_COUNTER_MAX_SIZE)
			m_FrameTimeCounter.erase(m_FrameTimeCounter.begin());
	}

	// Check if the timer needs to be reset
	if (m_Timer >= rle::time::s_1<>)
	{
		for (const auto time : m_FrameTimeCounter)
			m_AverageFrameTime += time;
		m_AverageFrameTime /= static_cast<float>(m_FrameTimeCounter.size());

		m_Timer -= rle::time::step_sec(1.0);
	}
}

void anvil::DeveloperPanel::onPanelDraw(rle::Renderer2D& renderer)
{
	if (ImGui::Begin("Debugger", &m_Open))
	{
		ImGui::Text("Frame Info:");
		ImGui::BulletText("Average Frame Time: %f", m_AverageFrameTime);
		ImGui::BulletText("Average FPS: %i", static_cast<std::uint32_t>(1000.0f / m_AverageFrameTime));
		ImGui::PlotLines("Frame Times",
						 m_FrameTimeCounter.data(),
						 static_cast<int>(m_FrameTimeCounter.size()),
						 0,
						 nullptr,
						 0.0f,
						 10.0f,
						 ImVec2(0.0f, 40.0f));
		ImGui::Checkbox("Paused", &m_FramePlotPaused);

		// This here so its ready for scene debugging info
		//ImGui::Separator();
		//ImGui::Text("Scene:");

		ImGui::End();
	}
}
