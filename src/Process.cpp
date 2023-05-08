#include "fsgl_pch.hpp"
#include "fsgl/Core/Process.hpp"



void fsgl::Process::init(int argc, char* argv[])
{
    onProcessInit(argc, argv);
}

int fsgl::Process::execute()
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

void fsgl::Process::exit()
{
    m_Executing = false;
}

void fsgl::Process::onProcessInit(int argc, char* argv[])
{
    
}

void fsgl::Process::onProcessExit()
{

}
