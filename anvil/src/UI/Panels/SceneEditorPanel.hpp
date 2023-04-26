#pragma once

// --- GLM ---
#include <glm/vec2.hpp>

// --- RLE ---
#include <RLE/Node/Node.hpp>
#include <RLE/Rendering/FrameBuffer.hpp>
#include <RLE/Rendering/GraphicsHandle.hpp>
#include <RLE/Rendering/2D/View.hpp>

// --- Anvil ---
#include "../ImGui/ImGuiPanel.hpp"



namespace anvil
{
    class SceneEditorPanel : public ImGuiPanel
    {
    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

        // Constructor
        SceneEditorPanel(std::weak_ptr<rle::Node> scene_node);

        // Default destructor
        ~SceneEditorPanel() = default;



        ////////////////////////////////////////////////////////////////////////////////
        // - OVERRIDES -----------------------------------------------------------------
        
        // Inherited via rle::Panel
        virtual void onPanelEnter() override;
        virtual void onPanelExit() override;
        virtual void onPanelUpdate(const rle::time::step_ms delta) override;

        // Inherited via ImGuiPanel
        virtual void onDraw(rle::Renderer2D& renderer) override;
        virtual void onImGuiDraw() override;



    private:
        // - Rendering -
        std::shared_ptr<rle::FrameBuffer> m_FrameBuffer;
        std::shared_ptr<rle::GraphicsHandle> m_GraphicsHandle;
        glm::ivec2 m_ViewportSize = { 0, 0 };

        // - Scene -
        rle::View m_View;
        std::weak_ptr<rle::Node> m_SceneNode;
    };
}
