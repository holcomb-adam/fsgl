#include "RLEpch.hpp"
#include "RLE/Rendering/RenderingAPI.hpp"



rle::RenderingAPI::API rle::RenderingAPI::getAPI()
{
    return s_API;
}

rle::RenderingAPI::RenderingAPI(const API api)
{
    s_API = api;
}
