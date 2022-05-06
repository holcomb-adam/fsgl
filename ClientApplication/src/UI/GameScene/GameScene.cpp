#include "GameScene.h"

// sdl library includes
#include <SDL_events.h>

// rle library includes
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
	// get the current key states
	const auto states = SDL_GetKeyboardState(nullptr);

	// move camera around
	if (states[SDL_SCANCODE_W])
		m_Camera.move(0.0f, 0.0f, CAMERA_MOVE_SPEED);
	if (states[SDL_SCANCODE_S])
		m_Camera.move(0.0f, 0.0f, -CAMERA_MOVE_SPEED);
	if (states[SDL_SCANCODE_D])
		m_Camera.move(CAMERA_MOVE_SPEED, 0.0f, 0.0f);
	if (states[SDL_SCANCODE_A])
		m_Camera.move(-CAMERA_MOVE_SPEED, 0.0f, 0.0f);
	if (states[SDL_SCANCODE_SPACE])
		m_Camera.move(0.0f, CAMERA_MOVE_SPEED, 0.0f);
	if (states[SDL_SCANCODE_LCTRL])
		m_Camera.move(0.0f, -CAMERA_MOVE_SPEED, 0.0f);
}

bool rle::GameScene::draw(const EngineRenderer& renderer) const
{
	for (const auto obj : m_SceneObjects)
		if (obj)
			renderer.render3D(obj->m_Mesh, m_Camera, obj->m_Transform);

	return true;
}

void rle::GameScene::keyPressEvent(const SDL_KeyboardEvent& event)
{
	if (event.keysym.mod == KMOD_CTRL)
		switch (event.keysym.scancode)
		{
		case SDL_SCANCODE_W: // toggle wireframe
			m_Camera.setWireFrame(!m_Camera.isWireFrame());
			break;

		case SDL_SCANCODE_L:
			//m_Camera.li;
			break;

		default:
			// do nothing...
			break;
		}
}
