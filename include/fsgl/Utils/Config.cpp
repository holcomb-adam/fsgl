#include "FSGLpch.hpp"
#include "FSGL/Utils/Config.hpp"



bool fsgl::Config::hasSection(const std::string &section) const
{
    return m_Data.find(section) != m_Data.end();
}

bool fsgl::Config::hasKey(const std::string &section, const std::string &key) const
{
    return m_Data.at(section).find(key) != m_Data.at(section).end();
}
