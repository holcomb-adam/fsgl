#pragma once

// --- Standard ---
#include <any>
#include <map>
#include <string>



namespace fsgl
{
    class Config
    {
    public:
        /// @brief 
        Config() = default;

        /// @brief 
        ~Config() = default;



        /// @brief 
        /// @param section 
        /// @return 
        bool hasSection(const std::string& section) const;

        /// @brief 
        /// @param section 
        /// @param key 
        /// @return 
        bool hasKey(const std::string& section, const std::string& key) const;

        /// @brief 
        /// @tparam T 
        /// @param section 
        /// @param key 
        /// @return 
        template<class T>
        T get(const std::string& section, const std::string& key) const;

        /// @brief 
        /// @tparam T 
        /// @param section 
        /// @param key 
        /// @param val 
        template<class T>
        void set(const std::string& section, const std::string& key, T&& val);

        /// @brief 
        /// @tparam T 
        /// @param section 
        /// @param key 
        /// @param dval 
        /// @return 
        template<class T>
        T getOrDefault(const std::string& section, const std::string& key, T&& dval);



    private:
        std::map<std::string, std::map<std::string, std::any>> m_Map;
    };



    #include "Config.inl"
}
