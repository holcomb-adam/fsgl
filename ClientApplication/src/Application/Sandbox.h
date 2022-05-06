#pragma once

// rle library includes
#include <RLE.h>
#include <Rendering/Graphics/3D/GameSceneObject.h>



namespace rle
{
	namespace b_ren
	{
		////////////////////////////////////////////////////////////////////////////////
		// - RLE CLIENT BRANCH ---------------------------------------------------------

		class Sandbox final : public rle::EngineBase
		{
		public:
			// rle default ctor
			Sandbox(RLE_CTOR_ARGS);

			// default dtor
			~Sandbox() = default;

			// Inherited via EngineBase
			virtual std::size_t init() override;
			virtual void update(const float delta) override;
			virtual bool render() const override;

		private:
			GameSceneObject m_Cube;
		};
	}
}

