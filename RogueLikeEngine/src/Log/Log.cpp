#include "Log.h"

#include <fstream>
#include <thread>
#include <unordered_map>
#include <vector>



namespace rle
{
    namespace log
    {

// this directive frees some memory from defines and
// static allocations
#ifdef RLE_LOGGING

        namespace detail
        {
            static const std::unordered_map<std::uint8_t, std::string> severity_tags
            {
                { INFO, "[INFO]" },
                { WARN, "[WARN]" },
                { ERR, "[ERR]" }
            };

            static std::ofstream ofs;
        }



        bool init(const std::string& path)
        {
            if (detail::ofs.is_open())
                detail::ofs.close();

            detail::ofs.open(path, std::ios_base::app);
            return detail::ofs.is_open();
        }

        void out(const std::uint8_t severity, const std::string& msg)
        {
            if (!detail::ofs.is_open())
                return;

            if (detail::severity_tags.find(severity) == detail::severity_tags.end())
                detail::ofs << "[UNKNOWN] ";
            else
                detail::ofs << detail::severity_tags.at(severity);

            std::time_t rawtime = 0;
            std::tm* info = nullptr;
            char buf[80] = { 0 };

            std::time(&rawtime);
            localtime_s(info, &rawtime);

            const auto& strt = std::strftime(buf, 80, "[%Y:%%m:%e:%R:%S]", info);
            detail::ofs << strt << msg << std::endl;
            detail::ofs.flush();
        }

#endif // RLE_LOGGING

    }
}
