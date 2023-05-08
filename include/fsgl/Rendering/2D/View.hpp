#pragma once

// --- GLM ---
#include <glm/mat4x4.hpp>
#include <glm/vec2.hpp>



namespace fsgl
{
    /// @brief 2D equivalent of a camera. Creates 2D view projection into 2D space.
    class View
    {
    public:
        static constexpr float NEAR_CLIP = 0.1f;
        static constexpr float FAR_CLIP = 1.0f;



    public:
        /// @brief 
        View() = default;

        /// @brief Create a 2D view projection
        /// @param w Position in screen space of the view
        /// @param h Rotation of the camera in degrees
        /// @param position 
        /// @param rotation 
        View(const float w,
             const float h,
             const glm::vec2& position = { 0.0f, 0.0f },
             const float rotation = 0.0f);

        /// @brief 
        ~View() = default;



        /// @brief 
        /// @return 
        glm::mat4 getProjectionMatrix() const;

        /// @brief 
        /// @return 
        glm::mat4 getViewMatrix() const;



        /// @brief 
        /// @param position 
        void setPosition(const glm::vec2& position);

        /// @brief 
        /// @param rotation_deg 
        void setRotation(const float rotation_deg);

        /// @brief 
        /// @param w 
        /// @param h 
        void setSize(const float w, const float h);

        /// @brief 
        /// @param offset 
        void move(const glm::vec2& offset);



    private:
        glm::vec2 m_Position;
        float m_Rotation = 0.0f;

        float m_Width = 0.0f;
        float m_Height = 0.0f;
    };
}
