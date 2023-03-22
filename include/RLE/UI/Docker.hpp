#pragma once

// --- Standard ---
#include <vector>

// --- RLE ---
#include "RLE/UI/Panel.hpp"



namespace rle
{
    /// @brief 
    class Docker
    {
    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

        /// @brief 
        Docker() = default;

        /// @brief 
        virtual ~Docker() = default;



        ////////////////////////////////////////////////////////////////////////////////
        // - GETTERS -------------------------------------------------------------------




        /// @brief Add a panel pointer to be managed by this docker.
        /// @param panel Panel to add
        /// @note The docker will assume ownership of the panel.
        void addPanel(Panel* panel);

        void updatePanels(const time::step_ms delta);
        void drawPanels(Renderer2D& renderer);



    private:
        std::vector<std::unique_ptr<Panel>> m_Panels;
    };
}
