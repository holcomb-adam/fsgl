#pragma once

// --- RLE ---
#include <RLE/UI/Layer.h>



namespace anvil
{
	// Will provide debugging information through ImGui
	class DebuggerLayer final : public rle::Layer
	{
		static constexpr std::size_t FRAME_TIME_COUNTER_MAX_SIZE = 300;
	public:
		// Inherited via Layer
		virtual void onEnter() override;
		virtual void onExit() override;
		virtual void onUpdate(const rle::time::step_ms delta) override;
		virtual void onRender(rle::Renderer& renderer) const override;



	private: 
		rle::time::step_sec m_Timer;
		
		std::vector<float> m_FrameTimeCounter;
		float m_AverageFrameTime = 0.0;

		mutable bool m_Open = true;
		mutable bool m_FramePlotPaused = false;
	};
}
