#include "fsgl_pch.hpp"
#include "fsgl/Resources/Resource.hpp"



fsgl::Resource::Resource(const bool local, const std::string& name, const std::string& path) : 
	m_Local(local),
	m_Name(name),
	m_Path(path)
{

}

bool fsgl::Resource::getIsLocal() const
{
	return m_Local;
}

const std::string& fsgl::Resource::name() const
{
	return m_Name;
}

const std::string& fsgl::Resource::path() const
{
	return m_Path;
}
