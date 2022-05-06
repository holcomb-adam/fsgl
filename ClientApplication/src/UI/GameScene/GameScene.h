#pragma once

// standard library includes
#include <vector>

// rle library includes
#include "EngineUI/EngineState.h"
#include "Rendering/Graphics/3D/Camera.h"
#include "Rendering/Graphics/3D/Mesh.h"
#include "Rendering/Graphics/3D/Transform.h"



namespace rle
{
	// rle forward declarations
	struct GameSceneObject;



	class GameScene final : public EngineState
	{
	public:
		static constexpr float CAMERA_MOVE_SPEED = 0.01f;

	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// default ctor
		GameScene() = default;

		// default dtor
		~GameScene() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// add a GameSceneObject reference to the scene
		const GameSceneObject* addObject(const GameSceneObject* obj);



		////////////////////////////////////////////////////////////////////////////////
		// - ENGINE BASE OVERRIDES -----------------------------------------------------

		// Inherited via EngineState
		virtual void onEnter() override;
		virtual void onExit() override;
		virtual void update(const float delta) override;
		virtual bool draw(const EngineRenderer& renderer) const override;

	protected:
		// Event handle overrides
		virtual void keyPressEvent(const SDL_KeyboardEvent& event) override;

	private:
		Camera m_Camera;

		std::vector<const GameSceneObject*> m_SceneObjects;
	};
}
