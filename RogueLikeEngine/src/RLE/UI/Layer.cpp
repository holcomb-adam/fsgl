#include "RLEpch.h"
#include "Layer.h"

rle::Layer::Layer(const std::string& name) : 
	m_DebugName(name)
{

}

const std::string& rle::Layer::name() const
{
	return m_DebugName;
}
