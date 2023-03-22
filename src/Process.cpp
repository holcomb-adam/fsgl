#include "RLEpch.hpp"
#include "RLE/Core/Process.hpp"



void rle::Process::init(int argc, char* argv[])
{
    onProcessInit(argc, argv);
}

int rle::Process::execute()
{
    m_Executing = true;

    auto last_elapsed_tm = time::now();

    while (m_Executing)
    {
        // Calculate the time elapsed
        const auto recent_tm = time::now();
        const auto delta_tm = recent_tm - last_elapsed_tm;
        last_elapsed_tm = recent_tm;

        onProcessUpdate(delta_tm);
    }

    return 0;
}

void rle::Process::exit()
{
    m_Executing = false;
}

void rle::Process::onProcessInit(int argc, char* argv[])
{
    
}

void rle::Process::onProcessExit()
{

}
