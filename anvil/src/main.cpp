// RLE Anvil entry point

// --- RLE ---
#include <RLE.hpp>
#include <RLE/Debug/Log.hpp>

// --- Anvil ---
#include "AnvilApplication.hpp"



int main(int argc, char* argv[])
{
    // Initialize client core
    if (!rle::core::initialize())
        return -1;

    // Create the rle anvil client
    std::unique_ptr<anvil::AnvilApplication> rle_engine = 
        std::make_unique<anvil::AnvilApplication>();

    // Initialize the engine
    rle_engine->init();

    return rle_engine->exec();
}
