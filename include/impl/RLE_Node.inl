#include "RLE_Node.hpp"



template<class T>
std::size_t rle::impl::getComponentTypeID()
{
    static auto ID = newComponentID();
    return ID;
}
