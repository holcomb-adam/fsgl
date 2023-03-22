#pragma once

// --- RLE ---
#include <RLE/Core/EngineState.hpp>
#include <RLE/Rendering/Renderer2D.hpp>
#include <RLE/UI/Docker.hpp>

// --- Anvil ---
#include "../UI/ImGui/ImGuiRenderer.hpp"



namespace anvil
{
    /// @brief Creates the necessary components for a scene editor
    class EditorState : public rle::EngineState
    {
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



    private:
        // UI
        ImGuiRenderer m_ImGuiRenderer;
        rle::Docker m_Docker;

        // 2D Scene rendering
        rle::Renderer2D m_Renderer2D;
    };
}
