#include "RLEpch.hpp"
#include "Layer.hpp"

rle::Layer::Layer(const std::string& name) : 
	m_Name(name)
{

}

const std::string& rle::Layer::name() const
{
	return m_Name;
}
