#include "RLEpch.hpp"
#include "RLE/Core/EngineState.hpp"



const std::string & rle::EngineState::getName() const
{
    return m_Name;
}

void rle::EngineState::enter()
{
    onStateEnter();
}

void rle::EngineState::update(const time::step_ms delta)
{
    onStateUpdate(delta);
}
