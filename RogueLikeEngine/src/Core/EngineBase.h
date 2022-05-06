#pragma once

// external includes
#include <SDL_events.h>

// Standard Library includes
#include <chrono>

// rle library includes
#include "EngineUI/EngineState.h"
#include "Rendering/EngineRenderer.h"
#include "Rendering/Graphics/3D/Mesh.h"
#include "Utils/FiniteStateMachine/FiniteStateMachine.h"



namespace rle
{
	// this class represents the base or application of the engine
	class EngineBase : public FiniteStateMachine<EngineState>
	{
	public:
		static const std::chrono::system_clock::time_point ENGINE_EPOCH;

	public:
		// ctor
		// takes an SDL_Renderer and an SDL_Window
		EngineBase(SDL_Renderer* sdl_ren, SDL_Window* sdl_win);

		// begins the engine's application loop
		int exec();

		// for post-instantiation initialization
		// returns code (0 is considered a safe return)
		virtual std::size_t init() = 0;

	protected:
		// update the client engine
		virtual void update(const float delta) = 0;

		// render the engine states
		// client side rendering possible as well
		virtual bool render() const = 0;

	private:
		// handle inputs given from the user
		void handleInput(const SDL_Event& event);

		// update the engine
		void engine_update(const float delta);

		// render the engine
		void engine_render() const;

	private:
		EngineRenderer m_Renderer;

		bool m_Executing = false;
	};
}
