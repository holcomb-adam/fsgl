#pragma once

// --- RLE ---
#include <RLE.hpp>



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



	private:
		////////////////////////////////////////////////////////////////////////////////
		// - OVERRIDES -----------------------------------------------------------------

		// Inherited via rle::Engine
		virtual void onEngineUpdate(const rle::time::step_ms delta) override;
		virtual void onEngineInit(int argc, char* argv[]) override;
	};
}
