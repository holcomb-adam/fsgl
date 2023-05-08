#include <cassert>



template <class T>
inline T fsgl::Config::get(const std::string &section, const std::string &key) const
{
    assert(hasSection(section));
    assert(hasKey(section, key));
    return std::any_cast<T>(m_Data.at(section).at(key));
}

template <class T>
inline void fsgl::Config::set(const std::string &section, const std::string &key, T &&val)
{
    if (!hasSection(section))
        m_Data.emplace(section, std::map<std::string, std::any>());
    if (!hasKey(section, key))
        m_Data.at(section).emplace(key, std::make_any<T>(std::forward<T>(val)));
    else
        m_Data.at(section).at(key).reset(std::forward<T>(val));
}

template <class T>
inline T fsgl::Config::getOrDefault(const std::string &section, const std::string &key, T &&dval)
{
    if (!hasSection(section) || !hasKey(section, key))
        set(section, key, std::forward<T>(dval));

    return get<T>(section, key);
}
