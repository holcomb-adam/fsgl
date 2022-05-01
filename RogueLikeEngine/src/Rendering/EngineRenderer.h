#pragma once

#include "Color.h"
#include "Math/Vector2.h"
#include "Graphics/3D/Transform.h"



// SDL2 forward declarations
struct SDL_Renderer;
struct SDL_Window;



namespace rle
{
	// rle forward declarations
	class Camera;
	class Drawable2D;
	class Renderable3D;



	// this class will perform rendering via SDL2
	// - accesses the renderer and window but doesnt not own
	class EngineRenderer final
	{
	public:
		// ctor
		// takes an SDL_Renderer to render to, and the window which the rendering will
		// be performed on
		EngineRenderer(SDL_Renderer* sdl_ren, SDL_Window* sdl_win);

		// explicit default dtor
		~EngineRenderer() = default;

		// get window size
		Vector2i windowSize() const;

		// draw a line
		void drawLine(const Vector2f& s, const Vector2f& e, const Color& color) const;

		// Renders a drawable on the screen
		void draw2D(const Drawable2D& drawable) const;

		// renders a 3D object
		void render3D(const Renderable3D& renderable, const Camera& camera, Transform transform) const;



		// Clears the current rendering
		// The color that will fill the screen after rendering
		void clear(const Color& clear_color) const;

		// Presents the current rendering to the screen
		void present() const;

	private:
		SDL_Renderer* m_SDL_Renderer = nullptr;
		SDL_Window* m_SDL_Window = nullptr;
	};
}
