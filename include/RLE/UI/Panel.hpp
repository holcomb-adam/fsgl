#pragma once

// --- GLM ---
#include <glm/vec2.hpp>

// --- RLE ---
#include "RLE/Core/Time.hpp"
#include "RLE/Events/Eventable.hpp"



namespace rle
{
    // --- Forward Declarations ---
    class Renderer2D;



    class Panel : public Eventable
    {
    public:
        Panel(const std::string& name);



        void setSize(const glm::u32vec2& size);

        const std::string& name() const;

        const glm::vec2& getPosition() const;

        /// @brief 
        /// @return 
        const glm::u32vec2& getSize() const;




        void setPosition(const glm::vec2& position);





        void enter();
        void update(const time::step_ms delta);
        void draw(Renderer2D& renderer);




    private:
        virtual void onPanelEnter();
        virtual void onPanelExit();
        virtual void onPanelUpdate(const time::step_ms delta) = 0;
        virtual void onPanelDraw(Renderer2D& renderer) = 0;


    private:
        std::string m_Name = "";
        glm::u32vec2 m_Size;
        glm::vec2 m_Position;
    };
}
