#pragma once

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

        const std::string& name() const;

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
    };
}
