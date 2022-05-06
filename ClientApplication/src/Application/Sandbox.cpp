#include "Sandbox.h"

// rle library includes
#include "Log/Log.h"
#include "Math/Constants.h"

// client includes
#include "UI/GameScene/GameScene.h"

#include <iostream>



// RLE Engine library entrance
RLE_INSTANCE(rle::b_ren::Sandbox)



////////////////////////////////////////////////////////////////////////////////
// - RLE CLIENT BRANCH ---------------------------------------------------------

rle::b_ren::Sandbox::Sandbox(RLE_CTOR_ARGS) : RLE_ENGINE_CONSTRUCT
{

}

std::size_t rle::b_ren::Sandbox::init()
{
	rle::Vector<double, 5> vec;

	// add game scene state
	auto& game_scene = pushState<GameScene>();

	// initialize the test cube
	m_Cube.m_Mesh.load("test_cube.obj");
	m_Cube.m_Transform.setPosition(0.0f, 0.0f, 5.0f);

	// add object to the rendering scene
	game_scene.addObject(&m_Cube);

	// output to logs
	RLE_LOG_OUT(log::INFO, "RLE client successfully initialized!");

	return 0;
}

void rle::b_ren::Sandbox::update(const float delta)
{
	// little static var for holding a time difference
	static float r = 0.0f;
	r += delta * 0.0002f * math::constants::PI_F;

	// move the cube in a circle
	const auto tx = cos(r);
	const auto ty = sin(r);

	m_Cube.m_Transform.setPosition(tx * 3.0f, ty * 3.0f, 5.0f);
	m_Cube.m_Transform.setRotation({ 0.0f, 0.0f, r }); // rotate the cube in a circle
}

bool rle::b_ren::Sandbox::render() const
{
	return true;
}
