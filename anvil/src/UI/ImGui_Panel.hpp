#pragma once

// --- imgui ---
#include <imgui/imgui.h>

// --- RLE ---
#include <RLE/UI/Panel.hpp>

// --- Anvil ---
#include "../Utils.hpp"



namespace anvil
{
    class ImGui_Panel : public rle::Panel
    {
    public:
        inline ImGui_Panel(const std::string& name) : 
            m_Name(name) { }

        virtual void onDraw(rle::Renderer2D& renderer) = 0;
        virtual void onImGuiBegin() = 0;

        inline virtual const std::string& getName() const override
        {
            return m_Name;
        }

        inline virtual const glm::vec2& getPosition() const override
        {
            return m_Position;
        }

        inline virtual const glm::vec2& getSize() const override
        {
            return m_Size;
        }

        inline virtual void setPosition(const glm::vec2& position) override
        {
            m_Position = position;
        }

        inline virtual void setSize(const glm::vec2& size) override
        {
            m_Size = size;
        }



    private:
        inline virtual void onPanelDraw(rle::Renderer2D& renderer) override
        {
            onDraw(renderer);

            //ImGui::SetNextWindowSize(to_imvec(getSize()));
            //ImGui::SetNextWindowPos(to_imvec(getPosition()));

            // Begin an ImGui window
            if (ImGui::Begin(m_Name.c_str(), &m_Open))
            {
                onImGuiBegin();
                ImGui::End();
            }
        }


    private:
        bool m_Open = true;
        std::string m_Name;

        /// @todo need to make into ImVec2
        glm::vec2 m_Size;
        glm::vec2 m_Position;
    };
}
