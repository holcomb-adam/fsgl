#pragma once

// --- Standard ---
#include <vector>

// --- RLE ---
#include "RLE/UI/Panel.hpp"



namespace rle
{
    /// @brief 
    class DockSpace
    {
    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------



        /// @brief 
        DockSpace() = default;

        /// @brief 
        ~DockSpace() = default;



        ////////////////////////////////////////////////////////////////////////////////
        // - SETTERS -------------------------------------------------------------------

        /// @brief 
        /// @param width 
        /// @param height 
        void setBoundingSize(std::uint32_t width, std::uint32_t height);



        /// @brief Add a panel pointer to be managed by this docker.
        /// @param panel Panel to add
        /// @note The docker will assume ownership of the panel.
        void addPanel(Panel* panel);

        void updatePanels(const time::step_ms delta);

        void draw(Renderer2D& renderer);



    private:
        // - Info -
        std::uint32_t m_Width = 0;
        std::uint32_t m_Height = 0;

        std::vector<std::unique_ptr<Panel>> m_Panels;
    };
}
