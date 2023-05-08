#pragma once

// --- Standard ---
#include <functional>

// --- fsgl ---
#include "fsgl/Utils/UniqueID.hpp"



namespace fsgl
{
    /// @brief 
    /// @tparam ...Args 
    template<class T_Emitter, class... T_Args>
    class Signal
    {
    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - STATIC MEMBERS ------------------------------------------------------------

        /// @brief 
        using Subscription_Caller_t = std::function<void(T_Emitter&, T_Args...)>;




        UniqueID<Signal<T_Emitter, T_Args...>> UID;



    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

        /// @brief 
        Signal() = default;

        /// @brief 
        ~Signal() = default;



        ////////////////////////////////////////////////////////////////////////////////
        // - OPERATIONS ----------------------------------------------------------------

        /// @brief 
        /// @param subscription_callback 
        void subscribe(const Subscription_Caller_t& subscription_callback);

        /// @brief 
        /// @param emitter 
        /// @param ...args 
        void emit(T_Emitter& emitter, T_Args... args);



    private:
        std::vector<Subscription_Caller_t> m_Callers;
    };
}



#include "Signal.inl"
