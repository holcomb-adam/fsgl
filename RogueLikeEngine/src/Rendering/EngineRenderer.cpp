#include "EngineRenderer.h"

#include <SDL_render.h>

#include "Graphics/2D/Drawable2D.h"
#include "Graphics/3D/Renderable3D.h"

rle::EngineRenderer::EngineRenderer(SDL_Renderer* sdl_ren, SDL_Window* sdl_win) : 
	m_SDL_Renderer(sdl_ren),
	m_SDL_Window(sdl_win)
{
	
}

rle::Vector2i rle::EngineRenderer::windowSize() const
{
	Vector2i size;
	SDL_GetWindowSize(m_SDL_Window, &size.x, &size.y);
	return size;
}

void rle::EngineRenderer::drawLine(const Vector2f& s, const Vector2f& e, const Color& color) const
{
	SDL_SetRenderDrawColor(m_SDL_Renderer, color.red, color.green, color.blue, color.alpha);
	SDL_RenderDrawLine(m_SDL_Renderer, 
		static_cast<int>(s.x),
		static_cast<int>(s.y),
		static_cast<int>(e.x),
		static_cast<int>(e.y)
	);
}

void rle::EngineRenderer::draw2D(const Drawable2D& drawable) const
{
	drawable.draw(*this);
}

void rle::EngineRenderer::render3D(const Renderable3D& renderable, const Camera& camera, Transform transform) const
{
	renderable.render3D(*this, camera, transform);
}

void rle::EngineRenderer::clear(const Color& clear_color) const
{
	SDL_SetRenderDrawColor(
		m_SDL_Renderer,
		clear_color.red,
		clear_color.green,
		clear_color.blue,
		clear_color.alpha);
	SDL_RenderClear(m_SDL_Renderer);
}

void rle::EngineRenderer::present() const
{
	SDL_RenderPresent(m_SDL_Renderer);
}
