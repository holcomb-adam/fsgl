#include "RLEpch.hpp"
#include "Renderer.hpp"

// --- RLE ---
#include "Renderable.hpp"
#include "RenderCommands.hpp"
#include "Camera.hpp"
#include "Shader.hpp"
#include "VertexArray.hpp"



void rle::Renderer::beginScene(const std::unique_ptr<Camera>& camera)
{
	m_ViewProjection = camera->calcViewProjectionMatrix();
}

void rle::Renderer::endScene()
{
	// Frame buffer stuff here...
}

void rle::Renderer::submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vao)
{
	shader->bind();
	shader->uploadUniform("u_ProjectionMatrix", m_ViewProjection);
	
	vao->bind();
	RenderCommands::draw(vao);
}

void rle::Renderer::submit(const Renderable& renderable)
{
	renderable.onRender(*this);
}
