#pragma once

#include <SDL_events.h>

#include "EngineUI/EngineState.h"
#include "Rendering/EngineRenderer.h"
#include "Rendering/Graphics/3D/Mesh.h"
#include "Utils/FiniteStateMachine/FiniteStateMachine.h"



namespace rle
{
	// this class represents the base of the engine
	class EngineBase : public FiniteStateMachine<EngineState>
	{
	public:
		// ctor
		// takes an SDL_Renderer and an SDL_Window
		EngineBase(SDL_Renderer* sdl_ren, SDL_Window* sdl_win);

		// begins the engine's application loop
		int exec();

	protected:
		// handle inputs given from the user
		void handleInput(const SDL_Event& event);

		// update the engine and then all proceeding panels / states
		void update(const float delta);

		// render the engine states
		bool render() const;

	private:
		EngineRenderer m_Renderer;

		bool m_Executing = false;
	};
}
