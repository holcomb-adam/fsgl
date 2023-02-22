#include "RLEpch.hpp"
#include "RLE/Resources/Resource.hpp"



rle::Resource::Resource(const bool local, const std::string& name, const std::string& path) : 
	m_Local(local),
	m_Name(name),
	m_Path(path)
{

}

bool rle::Resource::getIsLocal() const
{
	return m_Local;
}

const std::string& rle::Resource::name() const
{
	return m_Name;
}

const std::string& rle::Resource::path() const
{
	return m_Path;
}
