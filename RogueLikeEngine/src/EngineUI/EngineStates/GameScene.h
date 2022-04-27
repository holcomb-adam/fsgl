#pragma once

#include "EngineUI/EngineState.h"
#include "Rendering/Graphics/3D/Camera.h"
#include "Rendering/Graphics/3D/Mesh.h"
#include "Rendering/Graphics/3D/Transform.h"



namespace rle
{
	class GameScene final : public EngineState
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// default ctor
		GameScene() = default;

		// default dtor
		~GameScene() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - ENGINE STATE OVERRIDES ----------------------------------------------------

		// Inherited via EngineState
		virtual void onEnter() override;
		virtual void onExit() override;
		virtual void update(const float delta) override;
		virtual bool draw(const EngineRenderer& renderer) const override;

	private:
		Mesh m_Cube;
		Transform m_CubeTransform;

		Camera m_Camera;
	};
}
