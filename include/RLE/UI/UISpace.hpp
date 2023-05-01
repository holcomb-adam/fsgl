#pragma once

// --- Standard ---
#include <memory>
#include <vector>

// --- rle ---
#include "RLE/UI/Panel.hpp"



namespace rle
{
    /// @brief Interface for defining a region of space, typically in screen space, to
    ///        draw and manage UI elements.
    class UISpace
    {
    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

        /// @brief Construct the UI space
        UISpace() = default;

        /// @brief Destruct the UI Space
        ~UISpace() = default;



        ////////////////////////////////////////////////////////////////////////////////
        // - GETTERS -------------------------------------------------------------------

        /// @brief Get the vector of panels
        /// @return A vector of unique pointers of panels
        const std::vector<std::unique_ptr<Panel>>& getPanels() const;



        ////////////////////////////////////////////////////////////////////////////////
        // - SETTERS -------------------------------------------------------------------

        /// @brief Set the bounding size of the UI space
        /// @param width The new width of UI space region
        /// @param height The new height of UI space region
        void setBoundingSize(std::uint32_t width, std::uint32_t height);



        ////////////////////////////////////////////////////////////////////////////////
        // - OPERATIONS ----------------------------------------------------------------

        /// @brief Add a panel pointer to be managed by this UI space.
        /// @param panel Panel to add
        /// @note The UI space will assume ownership of the panel and manage it's
        ///       lifetime.
        void addPanel(Panel* panel);

        /// @brief Iterate through and update all the panels in the UI space.
        /// @param delta Time step since last update
        void updatePanels(time::step_ms delta);

        /// @brief Draw UI space elements and iteratively draw panels
        /// @param renderer Renderer target to draw to
        void draw(Renderer2D& renderer);



    private:
        ////////////////////////////////////////////////////////////////////////////////
        // - VIRTUALS ------------------------------------------------------------------

        /// @brief Called when a panel is added to the UI space. This is used to manage
        ///        a panel when its added to the space.
        /// @param panel Panel that was added
        virtual void onAddPanel(std::unique_ptr<Panel>& panel) = 0;

        /// @brief Called to draw any custom UI elements
        virtual void onUIDraw() = 0;



    protected:
        // - Info -
        std::uint32_t m_Width = 0;
        std::uint32_t m_Height = 0;

        std::vector<std::unique_ptr<Panel>> m_Panels;
    };
}
