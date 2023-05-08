
template <class T_Emitter, class... T_Args>
inline void rle::Signal<T_Emitter, T_Args...>::subscribe(const Subscription_Caller_t& subscription_callback)
{
    m_Callers.push_back(subscription_callback);
}

template<class T_Emitter, class... T_Args>
inline void rle::Signal<T_Emitter, T_Args...>::emit(T_Emitter& emitter, T_Args... args)
{
    for (const auto& caller : m_Callers)
        caller(emitter, args...);
}
