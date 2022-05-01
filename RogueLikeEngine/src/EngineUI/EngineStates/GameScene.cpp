#include "GameScene.h"

#include "Rendering/EngineRenderer.h"
#include "Rendering/Graphics/3D/GameSceneObject.h"

const rle::GameSceneObject* rle::GameScene::addObject(const GameSceneObject* obj)
{
	m_SceneObjects.push_back(obj);
	return obj;
}

void rle::GameScene::onEnter()
{
}

void rle::GameScene::onExit()
{

}

void rle::GameScene::update(const float delta)
{

}

bool rle::GameScene::draw(const EngineRenderer& renderer) const
{
	for (const auto obj : m_SceneObjects)
		if (obj)
			renderer.render3D(obj->m_Mesh, m_Camera, obj->m_Transform);

	return true;
}
