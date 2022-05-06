#include "EngineBase.h"

#include <chrono>

// the very start of the application
const std::chrono::system_clock::time_point rle::EngineBase::ENGINE_EPOCH = std::chrono::system_clock::now();

rle::EngineBase::EngineBase(SDL_Renderer* sdl_ren, SDL_Window* sdl_win) : 
	m_Renderer(sdl_ren, sdl_win)
{

}

int rle::EngineBase::exec()
{
	// set execution flag
	m_Executing = true;

	// get a starting point to
	auto last_elapsed = std::chrono::steady_clock::now();

	// being the application loop
	while (m_Executing)
	{
		// handle inputs given from the user
		SDL_Event event{};
		while (SDL_PollEvent(&event))
			handleInput(event);

		const auto recent_time = std::chrono::steady_clock::now();
		const auto elapsed_delta = (recent_time - last_elapsed).count();
		const auto elapsed_delta_f = static_cast<float>(elapsed_delta) * 1e-6f;

		// update this engine level first...
		// then the client engine level
		engine_update(elapsed_delta_f);

		// set the last elapsed time
		last_elapsed = recent_time;

		// same process as the updating
		engine_render();
	}

	return 0;
}

void rle::EngineBase::handleInput(const SDL_Event& event)
{
	switch (event.type)
	{
	case SDL_QUIT:
		m_Executing = false;
		break;

	// THIS NEEDS TO BE CHANGED EVENTUALLY
	case SDL_KEYDOWN:
		topState().keyPressEvent(event.key);
		break;
	}
}

void rle::EngineBase::engine_update(const float delta)
{
	update(delta);

	if (!empty())
		topState().update(delta);
}

void rle::EngineBase::engine_render() const
{
	m_Renderer.clear(rle::color_constants::BLACK);

	// render engine first
	render();

	if (!empty())
		topState().draw(m_Renderer);

	m_Renderer.present();
}
