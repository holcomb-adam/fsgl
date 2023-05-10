#pragma once

// --- glm ---
#include <glm/vec2.hpp>

// --- Standard ---
#include <string>

// --- fsgl ---
#include "fsgl/Core/Time.hpp"



namespace fsgl
{
    // --- Forward Declarations ---
    class Renderer2D;



    /// @brief Abstract class to represent a region of UI space for displaying
    ///        information to the user in a GUI format.
    class Panel
    {
    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

        /// @brief Construct the panel
        Panel() = default;

        /// @brief Destruct the panel
        virtual ~Panel()= default;



        ////////////////////////////////////////////////////////////////////////////////
        // - VIRTUALS ------------------------------------------------------------------

        /// @brief Get the name of the panel
        /// @return A string representing the panel's name
        virtual const std::string& getName() const = 0;

        /// @brief Get the position of the panel in UI space
        /// @return A 2D vector representing the position
        virtual const glm::vec2& getPosition() const = 0;

        /// @brief Get the size of the panel in UI space
        /// @return A 2D vector representing the size
        virtual const glm::vec2& getSize() const = 0;

        /// @brief Set the position of the panel in UI space
        /// @param position A 2D vector representing the new position
        virtual void setPosition(const glm::vec2& position) = 0;

        /// @brief Set the size of the panel in UI space
        /// @param size The new size of the panel
        virtual void setSize(const glm::vec2& size) = 0;

        /// @brief Called by the UI space to initialize the panel post-instantiation
        virtual void onPanelEnter() = 0;

        /// @brief Called to do any necessary clean up pre-deinstantion
        virtual void onPanelExit() = 0;

        /// @brief Called when the panel is being updated
        /// @param delta Time step in milliseconds since last update
        virtual void onPanelUpdate(const time::step_ms delta) = 0;

        /// @brief Called to draw the panel
        /// @param renderer Renderer target to draw to
        virtual void onPanelDraw(Renderer2D& renderer) = 0;
    };
}
