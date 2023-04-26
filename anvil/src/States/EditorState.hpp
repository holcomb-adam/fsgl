#pragma once

// --- RLE ---
#include <RLE/Core/EngineState.hpp>
#include <RLE/Rendering/GraphicsHandle.hpp>
#include <RLE/Rendering/Renderer2D.hpp>
#include <RLE/UI/DockSpace.hpp>

// --- Anvil ---
#include "../UI/ImGui/ImGuiRenderer.hpp"



namespace anvil
{
    /// @brief Creates the necessary components for a scene editor
    class EditorState : public rle::EngineState
    {
    public:
        static constexpr glm::vec4 SCREEN_CLEAR_COLOR = { 0.2f, 0.2f, 0.2f, 1.0f };



    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

        /// @brief Default constructor
        EditorState() = default;

        /// @brief Default destructor
        virtual ~EditorState() = default;



    private:
        ////////////////////////////////////////////////////////////////////////////////
        // - OVERRIDES -----------------------------------------------------------------

        // Inherited via rle::EngineState
        virtual void onStateEnter() override;
        virtual void onStateExit() override;
        virtual void onStateUpdate(const rle::time::step_ms delta) override;



        // - Helpers -
        void slot_onNodeSelect(rle::Node* node);



    private:
        // Access to graphics
        std::shared_ptr<rle::GraphicsHandle> m_GraphicsHandle;

        // UI
        ImGuiRenderer m_ImGuiRenderer;
        rle::DockSpace m_DockSpace;

        // 2D Scene rendering
        rle::Renderer2D m_Renderer2D;

        // Scene Information
        std::shared_ptr<rle::Node> m_SceneNode;
        std::weak_ptr<rle::Node> m_SelectedNode;
    };
}
