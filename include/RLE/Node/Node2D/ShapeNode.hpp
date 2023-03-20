#pragma once

// --- RLE ---
#include "RLE/Rendering/Shader.hpp"
#include "RLE/Rendering/VertexArray.hpp"
#include "RLE/Resources/Shape.hpp"
#include "RLE/Node/Node.hpp"



namespace rle
{
	class ShapeNode final : public Node
	{
	public:
		ShapeNode();


		// Set the shape resource
		void setShape(const std::shared_ptr<Shape>& shape);



	private:
		// Inherited via Node
		virtual void onRender(Renderer& target) const override;



	private:
		std::shared_ptr<Shape> m_Shape;

		// - Rendering Data -
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
		std::shared_ptr<VertexBuffer> m_VertexBuffer;
		std::shared_ptr<VertexArray> m_VertexArray;

		// - Shader Information -
		std::shared_ptr<Shader> m_Shader;
		glm::vec4 m_Color = { 0.0f, 0.0f, 0.0f, 0.0f };
	};
}
