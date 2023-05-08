#pragma once

// --- Standard ---
#include <string>

// --- RLE ---
#include "RLE/Core/Time.hpp"
#include "RLE/Utils/UniqueID.hpp"



namespace rle
{
    // --- Forward Declarations ---
    class Event;



    /// @brief Interface for defining how the engine process interacts with
    ///        other components of the engine.
    class EngineState
    {
    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - PUBLIC DATA ---------------------------------------------------------------

        /// @brief Public unique identifier
        UniqueID<EngineState> UID;



    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

        /// @brief Default constructor
        EngineState() = default;

        /// @brief Default destructor
        virtual ~EngineState() = default;



        ////////////////////////////////////////////////////////////////////////////////
        // - GETTERS -------------------------------------------------------------------

        /// @brief Get the name of the node
        /// @return String name reference
        const std::string& getName() const;



        ////////////////////////////////////////////////////////////////////////////////
        // - VIRTUALS ------------------------------------------------------------------

        /// @brief Initialize into a working state
        virtual void onStateEnter() = 0;

        /// @brief Cleanup and destroy state data
        virtual void onStateExit() = 0;

        /// @brief Update the state
        /// @param delta Time step since last update
        virtual void onStateUpdate(const time::step_ms delta) = 0;

        /// @brief 
        /// @param event 
        virtual bool onStateHandleEvent(const Event& event) = 0;



    private:
        std::string m_Name = "";
    };
}
