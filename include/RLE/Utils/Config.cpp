#include "RLEpch.hpp"
#include "RLE/Utils/Config.hpp"



bool rle::Config::hasSection(const std::string &section) const
{
    return m_Data.find(section) != m_Data.end();
}

bool rle::Config::hasKey(const std::string &section, const std::string &key) const
{
    return m_Data.at(section).find(key) != m_Data.at(section).end();
}
