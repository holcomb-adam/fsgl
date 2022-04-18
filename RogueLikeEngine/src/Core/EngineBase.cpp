#include "EngineBase.h"

#include <chrono>

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

		// update
		update(static_cast<float>(elapsed_delta) * 1e-6f);

		// set the last elapsed time
		last_elapsed = recent_time;

		// render
		render();
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
	}
}

void rle::EngineBase::update(const float delta)
{
	if (!empty())
		topState().update(delta);
}

bool rle::EngineBase::render() const
{
	m_Renderer.clear(rle::color_constants::BLACK);

	if (!empty())
		topState().draw(m_Renderer);

	m_Renderer.present();

	return true;
}