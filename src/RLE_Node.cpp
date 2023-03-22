#include "impl/RLE_Node.hpp"



std::size_t rle::impl::newComponentID()
{
    static std::size_t ID = 0;
    return ID++;
}
