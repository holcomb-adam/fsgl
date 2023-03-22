// RLE Anvil entry point

// --- RLE ---
#include <RLE.hpp>
#include <RLE/Debug/Log.hpp>

// --- Anvil ---
#include "AnvilApplication.hpp"
#include "States/EditorState.hpp"



int main(int argc, char* argv[])
{
    // Initialize client core
    if (!rle::core::initialize())
        return -1;

    // Create the rle anvil client
    std::unique_ptr<anvil::AnvilApplication> rle_engine = 
        std::make_unique<anvil::AnvilApplication>();

    // Initialize the engine process
    rle_engine->init(argc, argv);

    // Create the engine editor state
    auto* editor_state = new anvil::EditorState();
    rle_engine->pushState(editor_state);

    return rle_engine->execute();
}
