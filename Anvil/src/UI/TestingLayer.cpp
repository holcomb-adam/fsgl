#include "TestingLayer.hpp"

// --- External ---
#include <glm/gtc/matrix_transform.hpp>
#include <ImGui/imgui.h>
#include <ImGui/imgui_internal.h>

// --- RLE ---
#include <RLE/Core/Engine.h>
#include <RLE/Core/Input.hpp>
#include <RLE/Debug/Log.h>
#include <RLE/Rendering/IndexBuffer.hpp>
#include <RLE/Rendering/RenderCommands.hpp>
#include <RLE/Rendering/Renderer.hpp>
#include <RLE/Rendering/Vertex.hpp>
#include <RLE/Rendering/VertexArray.hpp>
#include <RLE/Rendering/VertexBuffer.hpp>



//// Our Vertex shader
//static const std::string quad_vert =
//	R"(
//		#version 330 core
//
//		layout(location = 0) in vec3 pos;
//
//		uniform mat4 u_ProjectionMatrix;
//
//		void main()
//		{
//			gl_Position = u_ProjectionMatrix * vec4(pos, 1.0);
//		}
//	)";
//
//// ... and our fragment shader
//static const std::string quad_frag =
//	R"(
//		#version 330 core
//
//		layout(location = 0) out vec4 color;
//
//		void main()
//		{
//			color = vec4(0.8, 0.2, 0.4, 1.0);
//		}
//	)";
//
//
//
//// Our Vertex shader
//static const std::string tri_vert =
//R"(
//		#version 330 core
//
//		layout(location = 0) in vec3 pos;
//		layout(location = 1) in vec4 i_color;
//
//		uniform mat4 u_ProjectionMatrix;
//
//		out vec4 o_color;
//
//		void main()
//		{
//			gl_Position = u_ProjectionMatrix * vec4(pos, 1.0);
//			o_color = i_color;
//		}
//	)";
//
//// ... and our fragment shader
//static const std::string tri_frag =
//R"(
//		#version 330 core
//
//		layout(location = 0) out vec4 color;
//		in vec4 o_color;
//
//		void main()
//		{
//			color = o_color;
//		}
//	)";
//
//
//
//// Helper struct for creating a shape
//// This gives a very vague idea of how meshes will work in RLE
//struct Shape
//{
//	std::shared_ptr<rle::Shader> shader;
//	std::shared_ptr<rle::VertexArray> vao;
//	std::shared_ptr<rle::VertexBuffer> vbo;
//	std::shared_ptr<rle::IndexBuffer> ibo;
//
//	// Just static stuff for ease of access
//	inline static std::vector<Shape> shapes;
//	inline static void create(
//		const std::string& vert_src,
//		const std::string& frag_src,
//		const std::size_t size,
//		const rle::Vertex* vertices,
//		const std::uint32_t count,
//		const std::uint32_t* indices)
//	{
//		Shape s = { 
//			rle::factory<rle::Shader>::create(vert_src, frag_src),
//			rle::factory<rle::VertexArray>::create(),
//			rle::factory<rle::VertexBuffer>::create(size, vertices),
//			rle::factory<rle::IndexBuffer>::create(indices, count)
//		};
//
//		s.vao->addVertexBuffer(s.vbo);
//		s.vao->setIndexBuffer(s.ibo);
//
//		shapes.push_back(s);
//	}
//};
//
//// Create a square
//const rle::Vertex quad_v[4] =
//{
//	{ .position = { -0.75f, -0.75f, 0.0f } },	// 0 - BL
//	{ .position = {  0.75f, -0.75f, 0.0f } },	// 1 - BR
//	{ .position = {  0.75f,  0.75f, 0.0f } },	// 2 - TL
//	{ .position = { -0.75f,  0.75f, 0.0f } }	// 3 - TR
//};
//const std::uint32_t quad_i[6] = { 0, 1, 2, 2, 3, 0 };
//Shape::create(quad_vert, quad_frag, sizeof(quad_v), quad_v, 6, quad_i);

//// Create a triangle
//const rle::Vertex tri_v[3] =
//{
//	{ .position = { -0.5f, -0.5f, 0.0f } },
//	{ .position = {  0.5f, -0.5f, 0.0f } },
//	{ .position = {  0.0f,  0.5f, 0.0f }, .color = { 0.57, 0.34, 0.78, 1.0 } }
//};
//const std::uint32_t tri_i[3] = { 0, 1, 2 };
//Shape::create(tri_vert, tri_frag, sizeof(tri_v), tri_v, 3, tri_i);



anvil::TestingLayer::TestingLayer() : 
	rle::Layer("TestingLayer")
{

}

void anvil::TestingLayer::onEnter()
{

}

void anvil::TestingLayer::onExit()
{

}

void anvil::TestingLayer::onUpdate(const rle::time::step_ms delta)
{

}

void anvil::TestingLayer::onRender(rle::Renderer& renderer) const
{

}
