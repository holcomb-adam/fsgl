#pragma once

// RLE Library includes
#include <RLE.h>



namespace client
{
	////////////////////////////////////////////////////////////////////////////////
	// - RLE CLIENT BRANCH ---------------------------------------------------------

	class EditorApplication final : public rle::Engine
	{
	public:
		// rle default ctor
		EditorApplication();

		// default dtor
		~EditorApplication() = default;

		// Inherited via EngineBase
		virtual std::size_t init() override;
		virtual void onUpdate(const rle::time::step_ms delta) override;
	};
}

