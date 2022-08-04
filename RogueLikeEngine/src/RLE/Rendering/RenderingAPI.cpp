#include "RLEpch.h"
#include "RenderingAPI.hpp"



rle::RenderingAPI::API rle::RenderingAPI::api()
{
    return s_API;
}

rle::RenderingAPI::RenderingAPI(const API api)
{
    s_API = api;
}
