#pragma once

// --- RLE ---
#include "RLE/Core/Time.hpp"
#include "RLE/Utils/NonCopyable.hpp"
#include "RLE/Utils/UniqueID.hpp"



namespace rle
{
    /// @brief Defines a persistent "keep-alive" loop.
    class Process : NonCopyable
    {
    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - PUBLIC MEMBERS ------------------------------------------------------------

        /// @brief Unique identifier
        UniqueID<Process> UID;



    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

        /// @brief Default constructor
        Process() = default;

        /// @brief Default destructor
        virtual ~Process() = default;



        ////////////////////////////////////////////////////////////////////////////////
        // - OPERATIONS ----------------------------------------------------------------

        /// @brief 
        /// @param argc 
        /// @param argv 
        void init(int argc = 0, char* argv[] = nullptr);

        /// @brief 
        int execute();

        /// @brief 
        void exit();



    private:
        ////////////////////////////////////////////////////////////////////////////////
        // - VIRTUALS ------------------------------------------------------------------

        /// @brief Initialize the process
        /// @param argc Number of arguments passed to the process
        /// @param argv C array of arguments
        virtual void onProcessInit(int argc, char* argv[]);

        /// @brief Update the process
        /// @param delta Time step since last update
        virtual void onProcessUpdate(const time::step_ms delta) = 0;

        /// @brief Destroy the process
        virtual void onProcessExit();



    private:
        bool m_Executing = false;
    };
}
