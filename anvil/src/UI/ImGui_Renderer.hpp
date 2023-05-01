#pragma once

// RLE Library includes
#include <RLE/Core/Engine.hpp>

namespace anvil
{
	class ImGuiRenderer final
	{

	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Default constructor
		ImGuiRenderer() = default;
		
		// Default destructor
		~ImGuiRenderer();



		////////////////////////////////////////////////////////////////////////////////
		// - OPERATIONS ----------------------------------------------------------------

		// Initialize the renderer and ImGui components and backends
		void init();

		// Update the ImGui io
		void update(const rle::time::step_ms delta);

		// Begin the ImGui rendering
		void begin() const;

		// End the ImGui rendering
		void end() const;


	private:
		rle::Engine* m_Engine = nullptr;
	};
}
