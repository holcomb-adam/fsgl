#include "GameScene.h"

#include "Math/Constants.h"
#include "Rendering/EngineRenderer.h"

void rle::GameScene::onEnter()
{
	m_Cube = {
		{ { 0.0f, 0.0f, 0.0f },	{ 0.0f, 1.0f, 0.0f }, { 1.0f, 1.0f, 0.0f } },
		{ { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 0.0f }, { 1.0f, 0.0f, 0.0f } },

		{ { 1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } },
		{ { 1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f }, { 1.0f, 0.0f, 1.0f } },

		{ { 1.0f, 0.0f, 1.0f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 1.0f, 1.0f } },
		{ { 1.0f, 0.0f, 1.0f }, { 0.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 1.0f } },

		{ { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f, 1.0f }, { 0.0f, 1.0f, 0.0f } },
		{ { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },

		{ { 0.0f, 1.0f, 0.0f }, { 0.0f, 1.0f, 1.0f }, { 1.0f, 1.0f, 1.0f } },
		{ { 0.0f, 1.0f, 0.0f }, { 1.0f, 1.0f, 1.0f }, { 1.0f, 1.0f, 0.0f } },

		{ { 1.0f, 0.0f, 1.0f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 0.0f, 0.0f } },
		{ { 1.0f, 0.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 1.0f, 0.0f, 0.0f } }
	};

	m_CubeTransform.setPosition(0.0f, 0.0f, 2.0f);
}

void rle::GameScene::onExit()
{

}

void rle::GameScene::update(const float delta)
{
	static float r = 0.0f;
	r += delta * 0.0002f * math::constants::PI;

	const auto tx = cos(r);
	const auto ty = sin(r);

	m_CubeTransform.setPosition(tx * 2.99f, 0.0f, ty * 2.99f + 3.0f);
}

bool rle::GameScene::draw(const EngineRenderer& renderer) const
{
	renderer.render3D(m_Cube, m_Camera, m_CubeTransform);

	return true;
}
